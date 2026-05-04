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
    QPushButton* btnReload;

    void initGUI();
    void connectSignals();
    void reloadList();

public:
    GUI(Service* srv);

private:
    void addProdus();
    void deleteProdus();
};