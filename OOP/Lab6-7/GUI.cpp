#include "GUI.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QString>

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

    btnReload = new QPushButton("Reload");
    rightLayout->addWidget(btnReload);

    setWindowTitle("Aplicatie produse");
    resize(800, 400);
}

void GUI::connectSignals() {
    QObject::connect(btnAdd, &QPushButton::clicked, this, &GUI::addProdus);
    QObject::connect(btnDelete, &QPushButton::clicked, this, &GUI::deleteProdus);
    QObject::connect(btnReload, &QPushButton::clicked, this, &GUI::reloadList);
}

void GUI::reloadList() {
    listaProduse->clear();

    auto produse = srv->getList();

    for (unsigned int i = 0; i < produse.size(); i++) {
        Produs p = produse[i];

        QString text =
            QString::number(p.getID()) + " | " +
            QString::fromStdString(p.getNume()) + " | " +
            QString::number(p.getPret()) + " | " +
            QString::fromStdString(p.getTip()) + " | " +
            QString::fromStdString(p.getProducator());

        listaProduse->addItem(text);
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