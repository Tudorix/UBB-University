//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_GUI_H
#define SIMUL_GUI_H
#include "Service.h"
#include <QWidget>
#include <QListWidget>
#include <QComboBox>

using namespace std;

class GUI : public QWidget {
    private:
        // Functie de initializare GUI
        void init();

        // Functie pt conectare semnale
        void connect();


        void onComboChanged();
        Service &service;

        QListWidget *listWidget;
        QComboBox *comboBox;
        QLineEdit *lineEdit;

        // functie de incarcare elemente in lista
        void load();
    public:
        // Constructor GUI
        GUI(Service &srv);
};


#endif //SIMUL_GUI_H
