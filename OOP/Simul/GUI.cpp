//
// Created by tudorix on 20.05.2026.
//

#include "GUI.h"
#include "GUI.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include  <QWindow>

GUI::GUI(Service &srv) : service(srv) {
    init();
    connect();
    load();
}

void GUI::init() {
    auto* layout = new QGridLayout;
    setLayout(layout);

    listWidget = new QListWidget;
    layout->addWidget(listWidget,0,0);

    comboBox = new QComboBox;
    layout->addWidget(comboBox,1,0);

    lineEdit = new QLineEdit;
    layout->addWidget(lineEdit,2,0);

    setWindowTitle("Simulare");
    resize(400,600);
}

void GUI::connect() {
    QObject::connect(lineEdit,&QLineEdit::textChanged,this,[this](QString text) {
        qDebug() << text;

        vector<Produs> produs = this->service.getAll();

        qDebug() << produs.size();
        listWidget->clear();
        vector <Produs> added;

            bool all = false;
            if (comboBox->currentText() == "Toate") {
                all = true;
            }

        for (unsigned int i = 0; i < produs.size(); i++) {
            if (produs[i].getName().find(text.toStdString()) != std::string::npos && (all || produs[i].getCategoria() == comboBox->currentText().toStdString())) {
            QListWidgetItem *item = new QListWidgetItem(
                QString::fromStdString(produs[i].getName()) + " (" +
                QString::number(produs[i].getYear()) + ")"
            );

            if (produs[i].getYear() > 2020) {
                item->setBackground(Qt::green);
            }else if (produs[i].getYear() <= 2020 && produs[i].getYear() > 2015) {
                item->setBackground(QColorConstants::Svg::orange);
            }else if (produs[i].getYear() <= 2015 && produs[i].getYear() > 2010) {
                item->setBackground(QColorConstants::Svg::yellow);
            }else {
                item->setBackground(QColorConstants::Svg::red);
            }

            listWidget->addItem(item);
            }
        }
    });

    QObject::connect(listWidget,&QListWidget::itemClicked,this,[this](QListWidgetItem *item) {
        QWindow *window = new QWindow;
        window->setWidth(300);
        window->setHeight(0);
        window->setTitle(item->text());
        window->show();
    });

    QObject::connect(comboBox, &QComboBox::currentTextChanged,
        [this](const QString& text) {

            vector <Produs> produs;
            listWidget->clear();
        produs = this->service.getAll();

        qDebug() << produs.size();

        vector <Produs> added;

            bool all = false;
            if (text == "Toate") {
                all = true;
            }

        for (unsigned int i = 0; i < produs.size(); i++) {
            if (all || produs[i].getCategoria() == text.toStdString()) {
            QListWidgetItem *item = new QListWidgetItem(
                QString::fromStdString(produs[i].getName()) + " (" +
                QString::number(produs[i].getYear()) + ")"
            );

            if (produs[i].getYear() > 2020) {
                item->setBackground(Qt::green);
            }else if (produs[i].getYear() <= 2020 && produs[i].getYear() > 2015) {
                item->setBackground(QColorConstants::Svg::orange);
            }else if (produs[i].getYear() <= 2015 && produs[i].getYear() > 2010) {
                item->setBackground(QColorConstants::Svg::yellow);
            }else {
                item->setBackground(QColorConstants::Svg::red);
            }

            listWidget->addItem(item);
            }
        }
        });
}


void GUI::load() {
    try {
        listWidget->clear();
        vector <Produs> produs;
        produs = this->service.getAll();

        qDebug() << produs.size();

        vector <Produs> added;

        comboBox->addItem("Toate");
        for (unsigned int i = 0; i < produs.size(); i++) {
            QListWidgetItem *item = new QListWidgetItem(
                QString::fromStdString(produs[i].getName()) + " (" +
                QString::number(produs[i].getYear()) + ")"
            );

            if (produs[i].getYear() > 2020) {
                item->setBackground(Qt::green);
            }else if (produs[i].getYear() <= 2020 && produs[i].getYear() > 2015) {
                item->setBackground(QColorConstants::Svg::orange);
            }else if (produs[i].getYear() <= 2015 && produs[i].getYear() > 2010) {
                item->setBackground(QColorConstants::Svg::yellow);
            }else {
                item->setBackground(QColorConstants::Svg::red);
            }

            int ver = 0;
            for (auto p : added) {
                if (p.getCategoria() == produs[i].getCategoria()) {
                    ver = 1;
                    break;
                }
            }
            if (ver == 0) {
                comboBox->addItem(QString::fromStdString(produs[i].getCategoria()));
                added.push_back(produs[i]);
            }

            //listWidget->addItem(item);
        }

    }catch (...) {
        QMessageBox::warning(this,"Error","Something went wrong!");
    }
}
