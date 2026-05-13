//
// Created by tudorix on 06.05.2026.
//

#include "WishGUI.h"
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>

WishGUI::WishGUI(Service* srv) {
    this->srv = srv;
    init();
    connections();
}

void WishGUI::init() {
    auto* layout = new QGridLayout;
    setLayout(layout);

    list = new QListWidget;
    layout->addWidget(list,0,0);

    id = new QLineEdit;
    id->setPlaceholderText(tr("id"));
    layout->addWidget(id,1,0);

    addButton = new QPushButton("Add");
    layout->addWidget(addButton,2,0);

    nr = new QLineEdit;
    nr->setPlaceholderText("number");
    layout->addWidget(nr,3,0);

    btnGen = new QPushButton("Generate");
    layout->addWidget(btnGen,4,0);

    fn = new QLineEdit;
    fn->setPlaceholderText("Ecport Filename");
    layout->addWidget(fn,5,0);

    btnExport = new QPushButton("Export");
    layout->addWidget(btnExport,6,0);

    btnEmpty = new QPushButton("Empty");
    layout->addWidget(btnEmpty,7,0);

    setWindowTitle(QString("Wish GUI"));
    resize(640,480);
}

void WishGUI::connections() {
    connect(btnEmpty,&QPushButton::clicked,this,&WishGUI::empty);
    connect(addButton,&QPushButton::clicked,this,&WishGUI::add);
    connect(btnGen,&QPushButton::clicked,this,&WishGUI::generate);
    connect(btnExport,&QPushButton::clicked,this,&WishGUI::Export);
}

void WishGUI::Export(){
    try {
        string expName = fn->text().toStdString();
        char* f = &expName[0];
        srv->exportWishlist(f);
    }catch (...) {
        QMessageBox::warning(this,"Error","Error in Export");
    }
}

void WishGUI::generate() {
    try {
        int p = nr->text().toInt();
        srv->generateWish(p);
        reload();
    }catch (...) {
        QMessageBox::warning(this,"Error","Error in generate");
    }
}

void WishGUI::reload() {
    list->clear();
    auto p = srv->getWish();
    for (unsigned int i = 0; i < p.size(); i++) {
        QString t = QString::fromStdString(std::to_string(p[i].getID()) + " | " + p[i].getNume() + " | " + p[i].getProducator());
        list->addItem(t);
    }
}

void WishGUI::add() {
    try {
        int p = id->text().toInt();

        srv->addWish(p);
        reload();
    }catch (...) {
        QMessageBox::warning(this,"Error","Invalid ID");
    }
}

void WishGUI::empty() {
    this->srv->empty();
    reload();
}
