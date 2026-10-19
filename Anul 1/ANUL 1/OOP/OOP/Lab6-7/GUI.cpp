#include "GUI.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QString>
#include "WishGUI.h"

GUI::GUI(Service* srv) : srv{ srv } {
    initGUI();
    connectSignals();
    reloadList();
}

void GUI::initGUI() {
    auto* mainLayout = new QHBoxLayout;
    setLayout(mainLayout);

    // stanga: lista produse
    listaProduse = new QListWidget;
    mainLayout->addWidget(listaProduse);

    // dreapta: formular + butoane
    auto* rightLayout = new QVBoxLayout;
    mainLayout->addLayout(rightLayout);

    auto* formLayout = new QFormLayout;

    editPret = new QLineEdit;
    editNume = new QLineEdit;
    editTip = new QLineEdit;
    editProducator = new QLineEdit;

    formLayout->addRow("Pret:", editPret);
    formLayout->addRow("Nume:", editNume);
    formLayout->addRow("Tip:", editTip);
    formLayout->addRow("Producator:", editProducator);

    rightLayout->addLayout(formLayout);

    btnAdd = new QPushButton("Adauga");
    rightLayout->addWidget(btnAdd);

    editIdStergere = new QLineEdit;
    editIdStergere->setPlaceholderText("ID de sters");
    rightLayout->addWidget(editIdStergere);

    btnDelete = new QPushButton("Sterge");
    rightLayout->addWidget(btnDelete);

    btnMod = new QPushButton("Modify");
    rightLayout->addWidget(btnMod);

    btnReload = new QPushButton("Reprint");
    rightLayout->addWidget(btnReload);

    btnWish = new QPushButton("Wishlist Window");
    rightLayout->addWidget(btnWish);

    //Sort
    auto* sortLayout = new QFormLayout;
    btnSortName = new QPushButton("Sort by Name");
    sortLayout->addWidget(btnSortName);

    btnSortPret = new QPushButton("Sort by Pret");
    sortLayout->addWidget(btnSortPret);

    mainLayout->addLayout(sortLayout);

    //Filt
    editField = new QLineEdit;
    editField->setPlaceholderText("Enter Criterie");
    sortLayout->addWidget(editField);

    btnFiltNume = new QPushButton("Filt Nume");
    btnFiltProducator = new QPushButton("Filt Producator");
    btnFiltTip = new QPushButton("Filt Tip");

    sortLayout->addWidget(btnFiltNume);
    sortLayout->addWidget(btnFiltProducator);
    sortLayout->addWidget(btnFiltTip);

    btnUndo = new QPushButton("Undo");
    sortLayout->addWidget(btnUndo);

    setWindowTitle("Main GUI");
    resize(800, 400);
}

void GUI::connectSignals() {
    QObject::connect(btnAdd, &QPushButton::clicked, this, &GUI::addProdus);
    QObject::connect(btnDelete, &QPushButton::clicked, this, &GUI::deleteProdus);
    QObject::connect(btnMod, &QPushButton::clicked, this, &GUI::modProdus);
    QObject::connect(btnSortName, &QPushButton::clicked, this, &GUI::sortName);
    QObject::connect(btnSortPret,&QPushButton::clicked,this,&GUI::sortPret);
    QObject::connect(btnReload,&QPushButton::clicked,this,&GUI::reloadList);
    connect(btnWish,&QPushButton::clicked,[this]() {
        auto* w2 = new WishGUI(this->srv);
        w2->show();
    } );

    connect(btnFiltNume,&QPushButton::clicked,this,&GUI::filtNume);
    connect(btnFiltProducator,&QPushButton::clicked,this,&GUI::filtProducator);
    connect(btnFiltTip,&QPushButton::clicked,this,&GUI::filtTip);
    connect(btnUndo,&QPushButton::clicked,this,&GUI::undo);

}

void GUI::filtNume() {
    try {
        string nume = editField->text().toStdString();

        char* n = &nume[0];
        auto produse = this->srv->filter(1,n);

        listaProduse->clear();
        QString header = "Produse filtrate";
        listaProduse->addItem(header);
        for (unsigned int i = 0; i < produse.size(); i++) {
            Produs p = produse[i];

            QListWidgetItem* item = new QListWidgetItem(listaProduse);

            QLabel* text = new QLabel(this);
            text->setText(
                QString::number(p.getID()) + " | " +
                QString::fromStdString(p.getNume()) + " | " +
                QString::number(p.getPret()) + " | " +
                QString::fromStdString(p.getTip()) + " | " +
                QString::fromStdString(p.getProducator()));

            if (p.getPret() < 50)
                text->setStyleSheet("color: rgb(255, 0, 0);");
            else if (p.getPret() >= 50 && p.getPret() < 100)
                text->setStyleSheet("color: rgb(0, 255, 0);");
            else
                text->setStyleSheet("color: rgb(0,0, 255);");

            listaProduse->addItem(item);
            listaProduse->setItemWidget(item, text);
        }
    }catch (...) {
        QMessageBox::warning(this, "Eroare","Date Invalide");
    }
}
void GUI::filtProducator() {
    try {
        string nume = editField->text().toStdString();

        char* n = &nume[0];
        auto produse = this->srv->filter(3,n);

        listaProduse->clear();
        QString header = "Produse filtrate";
        listaProduse->addItem(header);
        for (unsigned int i = 0; i < produse.size(); i++) {
            Produs p = produse[i];

            QListWidgetItem* item = new QListWidgetItem(listaProduse);

            QLabel* text = new QLabel(this);
            text->setText(
                QString::number(p.getID()) + " | " +
                QString::fromStdString(p.getNume()) + " | " +
                QString::number(p.getPret()) + " | " +
                QString::fromStdString(p.getTip()) + " | " +
                QString::fromStdString(p.getProducator()));

            if (p.getPret() < 50)
                text->setStyleSheet("color: rgb(255, 0, 0);");
            else if (p.getPret() >= 50 && p.getPret() < 100)
                text->setStyleSheet("color: rgb(0, 255, 0);");
            else
                text->setStyleSheet("color: rgb(0,0, 255);");

            listaProduse->addItem(item);
            listaProduse->setItemWidget(item, text);
        }
    }catch (...) {
        QMessageBox::warning(this, "Eroare","Date Invalide");
    }
}

void GUI::filtTip() {
    try {
        string nume = editField->text().toStdString();

        char* n = &nume[0];
        auto produs = this->srv->filter(2,n);

        listaProduse->clear();
        QString header = "Produse filtrate";
        listaProduse->addItem(header);
        for (unsigned int i = 0; i < produs.size(); i++) {
            Produs p = produs[i];

            QListWidgetItem* item = new QListWidgetItem(listaProduse);

            QLabel* text = new QLabel(this);
            text->setText(
                QString::number(p.getID()) + " | " +
                QString::fromStdString(p.getNume()) + " | " +
                QString::number(p.getPret()) + " | " +
                QString::fromStdString(p.getTip()) + " | " +
                QString::fromStdString(p.getProducator()));

            if (p.getPret() < 50)
                text->setStyleSheet("color: rgb(255, 0, 0);");
            else if (p.getPret() >= 50 && p.getPret() < 100)
                text->setStyleSheet("color: rgb(0, 255, 0);");
            else
                text->setStyleSheet("color: rgb(0,0, 255);");

            listaProduse->addItem(item);
            listaProduse->setItemWidget(item, text);
        }
    }catch (...) {
        QMessageBox::warning(this, "Eroare","Date Invalide");
    }
}

void GUI::reloadList() {
    listaProduse->clear();

    auto produse = srv->getList();

    for (unsigned int i = 0; i < produse.size(); i++) {
        Produs p = produse[i];

        QListWidgetItem* item = new QListWidgetItem(listaProduse);

        QLabel* text = new QLabel(this);
        text->setText(
            QString::number(p.getID()) + " | " +
            QString::fromStdString(p.getNume()) + " | " +
            QString::number(p.getPret()) + " | " +
            QString::fromStdString(p.getTip()) + " | " +
            QString::fromStdString(p.getProducator()));

        if (p.getPret() < 50)
            text->setStyleSheet("color: rgb(255, 0, 0);");
        else if (p.getPret() >= 50 && p.getPret() < 100)
            text->setStyleSheet("color: rgb(0, 255, 0);");
        else
            text->setStyleSheet("color: rgb(0,0, 255);");

        listaProduse->addItem(item);
        listaProduse->setItemWidget(item, text);
    }
}

void GUI::sortName() {
    try {
            vector<Produs> produse;
            produse = this->srv->sort(3,0);
            QString header = "Produse sortate";
            listaProduse->clear();
            listaProduse->addItem(header);
        for (unsigned int i = 0; i < produse.size(); i++) {
            Produs p = produse[i];

            QListWidgetItem* item = new QListWidgetItem(listaProduse);

            QLabel* text = new QLabel(this);
            text->setText(
                QString::number(p.getID()) + " | " +
                QString::fromStdString(p.getNume()) + " | " +
                QString::number(p.getPret()) + " | " +
                QString::fromStdString(p.getTip()) + " | " +
                QString::fromStdString(p.getProducator()));

            if (p.getPret() < 50)
                text->setStyleSheet("color: rgb(255, 0, 0);");
            else if (p.getPret() >= 50 && p.getPret() < 100)
                text->setStyleSheet("color: rgb(0, 255, 0);");
            else
                text->setStyleSheet("color: rgb(0,0, 255);");

            listaProduse->addItem(item);
            listaProduse->setItemWidget(item, text);
        }
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
    catch (...) {
        QMessageBox::warning(this, "Eroare", "Date invalide!");
    }
}

void GUI::sortPret() {
    try {
        vector<Produs> produse;
        produse = this->srv->sort(2,0);
        QString header = "Produse sortate";
        listaProduse->clear();
        listaProduse->addItem(header);
        for (unsigned int i = 0; i < produse.size(); i++) {
            Produs p = produse[i];

            QListWidgetItem* item = new QListWidgetItem(listaProduse);

            QLabel* text = new QLabel(this);
            text->setText(
                QString::number(p.getID()) + " | " +
                QString::fromStdString(p.getNume()) + " | " +
                QString::number(p.getPret()) + " | " +
                QString::fromStdString(p.getTip()) + " | " +
                QString::fromStdString(p.getProducator()));

            if (p.getPret() < 50)
                text->setStyleSheet("color: rgb(255, 0, 0);");
            else if (p.getPret() >= 50 && p.getPret() < 100)
                text->setStyleSheet("color: rgb(0, 255, 0);");
            else
                text->setStyleSheet("color: rgb(0,0, 255);");

            listaProduse->addItem(item);
            listaProduse->setItemWidget(item, text);
        }
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
    catch (...) {
        QMessageBox::warning(this, "Eroare", "Date invalide!");
    }
}

void GUI::undo() {
    try {
        srv->undo();
        reloadList();
    }
    catch (...) {
        QMessageBox::warning(this, "Eroare", "Date invalide!");
    }
}

void GUI::modProdus() {
    try {
        int pret = editPret->text().toInt();

        std::string nume = editNume->text().toStdString();
        std::string tip = editTip->text().toStdString();
        std::string producator = editProducator->text().toStdString();
        int id = editIdStergere->text().toInt();

        char* n = &nume[0];
        char* t = &tip[0];
        char* p = &producator[0];

        this->srv->modService(id,pret,p,t,p);
        reloadList();

    }catch (const Except& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }catch (...) {
        QMessageBox::warning(this, "Eroare", "Date invalide!");
    }
}

void GUI::addProdus() {
    try {
        int pret = editPret->text().toInt();

        std::string nume = editNume->text().toStdString();
        std::string tip = editTip->text().toStdString();
        std::string producator = editProducator->text().toStdString();

        srv->addService(
            pret,
            (char*)nume.c_str(),
            (char*)tip.c_str(),
            (char*)producator.c_str()
        );

        editPret->clear();
        editNume->clear();
        editTip->clear();
        editProducator->clear();

        reloadList();
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
    catch (...) {
        QMessageBox::warning(this, "Eroare", "Date invalide!");
    }
}

void GUI::deleteProdus() {
    try {
        int id = editIdStergere->text().toInt();

        srv->delService(id);

        editIdStergere->clear();
        reloadList();
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
    catch (...) {
        QMessageBox::warning(this, "Eroare", "ID invalid!");
    }
}