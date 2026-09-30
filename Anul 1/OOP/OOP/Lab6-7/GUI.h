#pragma once

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

#include "Service.h"

class GUI : public QWidget {
private:
    Service* srv;

    QListWidget* listaProduse;

    QLineEdit* editPret;
    QLineEdit* editNume;
    QLineEdit* editTip;
    QLineEdit* editProducator;

    QLineEdit* editIdStergere;

    QPushButton* btnAdd;
    QPushButton* btnDelete;
    QPushButton* btnMod;
    QPushButton* btnReload;
    QPushButton* btnSortName;
    QPushButton* btnSortPret;

    QLineEdit* editField;
    QPushButton* btnFiltTip;
    QPushButton* btnFiltNume;
    QPushButton* btnFiltProducator;
    QPushButton* btnUndo;

    QPushButton* btnWish;



    void initGUI();
    void connectSignals();
    void reloadList();
    void sortName();
    void sortPret();
    void filtNume();
    void filtProducator();
    void filtTip();
    void undo();

public:
    GUI(Service* srv);

private:
    void addProdus();
    void modProdus();
    void deleteProdus();
};