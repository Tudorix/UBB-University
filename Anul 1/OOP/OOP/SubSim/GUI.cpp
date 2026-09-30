#include "GUI.h"
#include <QGridLayout>
#include <QMessageBox>
#include <sstream>
#include <QCheckBox>
#include <QTableWidget>

GUI::GUI(Service* service) {
    this->service = service;
    INIT();
    CONNECT();
    reload();
    selected_id = -1;
}

void GUI::INIT() {
    auto *layout = new QGridLayout;
    setLayout(layout);

    listWidget = new QListWidget;
    layout->addWidget(listWidget,0,0);

    rent_button = new QPushButton();
    rent_button->setText("Rent");
    layout->addWidget(rent_button,1,0);

    sort_size = new QPushButton();
    sort_size->setText("Sort Size");
    layout->addWidget(sort_size,2,0);

    sort_price = new QPushButton();
    sort_price->setText("Sort Price");
    layout->addWidget(sort_price,3,0);

    reload_button = new QPushButton();
    reload_button->setText("Reload");
    layout->addWidget(reload_button,4,0);

    reload_checkbox = new QCheckBox("Check");
    layout->addWidget(reload_checkbox,5,0);

    reload_radio = new QRadioButton("Radio");
    layout->addWidget(reload_radio,6,0);

    reload_slider = new QSlider(Qt::Horizontal);
    layout->addWidget(reload_slider,7,0);

    table_widget = new QTableWidget();
    layout->addWidget(table_widget,8,0);

    QTableWidgetItem* item = new QTableWidgetItem("Item");
    item->setTextAlignment(Qt::AlignCenter);
    table_widget->

    setWindowTitle("Simulare Test");
    resize(600,400);
}

void GUI::reload() {
    listWidget->clear();
    auto p = service->get_all();
    qDebug()<<p.size();
    for (auto r : p) {
        QListWidgetItem* item = new QListWidgetItem(
        QString::fromStdString(r.get_name()) + ":" +
            QString::number(r.get_id()) + ":" +
            QString::number(r.get_price()));

        if (r.get_avaliable()) {
            item->setBackground(Qt::green);
        } else {
            item->setBackground(Qt::red);
        }

        listWidget->addItem(item);
    }
}

void GUI::CONNECT() {
    connect(listWidget, &QListWidget::itemClicked,
        this,
        [this](QListWidgetItem* item) {
            stringstream ss(item->text().toStdString());

            string nume;
            getline(ss, nume, ':');
            int this_id = service->find_by_name(nume);
            selected_id = this_id;
            qDebug() << item->text() << selected_id;
        });

    connect(rent_button, &QPushButton::clicked,this,&GUI::rent);
    connect(sort_size, &QPushButton::clicked,this,&GUI::ss);
    connect(sort_price,&QPushButton::clicked,this,&GUI::sp);
    connect(reload_button, &QPushButton::clicked,this,&GUI::reload);
    connect(reload_checkbox, &QCheckBox::stateChanged,this,[this](bool state){
        if (state) {
            QMessageBox::warning(this,"Checkbox","True");
        }
    });
    connect(reload_radio, &QRadioButton::clicked,this,[this](bool state) {
        if (state) {
            QMessageBox::warning(this,"Checkbox","True");
        }
    });
    connect(reload_slider, &QSlider::valueChanged,this,[this](int value) {
        QMessageBox::warning(this,"Slider",to_string(value).c_str());
    });
}

void GUI::ss() {
    try {
        listWidget->clear();
        vector<Rochie> v = service->sort_marime();
        qDebug()<<v.size();
        for (auto r : v) {
            QListWidgetItem* item = new QListWidgetItem(
                QString::fromStdString(r.get_name()) + ":" +
                QString::number(r.get_size()) + ":" +
                QString::number(r.get_price())
            );

            if (r.get_avaliable()) {
                item->setBackground(Qt::green);
            }else item->setBackground(Qt::red);

            listWidget->addItem(item);
        }

    }catch (...) {
        QMessageBox::warning(this,"Error","Cant rent");
    }
}

void GUI::sp() {
    try {

        vector<Rochie> v = service->sort_pret();
        qDebug()<<v.size();
        listWidget->clear();
        for (auto r : v) {
            QListWidgetItem* item = new QListWidgetItem(
                QString::fromStdString(r.get_name()) + ":" +
                QString::number(r.get_size()) + ":" +
                QString::number(r.get_price()));

            if (r.get_avaliable()) {
                item->setBackground(Qt::green);
            }else item->setBackground(Qt::red);
            listWidget->addItem(item);
        }

    }catch (...) {
        QMessageBox::warning(this,"Error","Cant rent");
    }
}

void GUI::rent() {
    try {
        if (selected_id == -1) { QMessageBox::warning(this,"Error","Cant rent"); return;}
        service->rent(selected_id);
        selected_id = -1;
        reload();
    }catch (...) {
        QMessageBox::warning(this,"Error","Cant rent");
    }
}


