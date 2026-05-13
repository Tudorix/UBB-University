//
// Created by tudorix on 06.05.2026.
//

#ifndef LAB6_7_WISHGUI_H
#define LAB6_7_WISHGUI_H
#include <qlistwidget.h>
#include <QPushButton>
#include <QWidget>

#include "Service.h"

class WishGUI : public QWidget {
private:
    Service *srv;
    void init();
    QListWidget* list;

    QLineEdit* id;
    QPushButton* addButton;

    QLineEdit* nr;
    QPushButton* btnGen;

    QLineEdit* fn;
    QPushButton* btnExport;
    QPushButton* btnEmpty;

    void empty();
    void connections();
    void reload();
    void add();
    void generate();
    void Export();

    public:
    WishGUI(Service* srv);
};

#endif //LAB6_7_WISHGUI_H
