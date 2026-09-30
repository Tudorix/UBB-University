#include <QApplication>
#include <string>
#include "Service.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QRadioButton>
#include <QTableWidget>

class GUI : public QWidget {
    private:
        Service* service;
        void INIT();
        void CONNECT();
        void reload();

        void rent();
        void ss();
        void sp();

        int selected_id;

        QListWidget *listWidget;
        QPushButton *rent_button;
        QPushButton *sort_size;
        QPushButton *sort_price;
        QPushButton *reload_button;

        QCheckBox *reload_checkbox;
        QRadioButton *reload_radio;
        QSlider *reload_slider;

        QTableWidget *table_widget;

    public:
    GUI(Service* service);
};
