#include "GUI.h"
#include "Repo.h"
#include "Service.h"
#include "Valid.h"
#include <QApplication>

#include "test.h"

int main(int argc, char** argv) {
    string fn = "/home/tudorix/UBB/UBB-University/OOP/Simul/save.txt";
    Repo repo(fn);
    Valid valid(repo);
    Service srv(repo, valid);
    test test(srv);

    QApplication app(argc, argv);
    GUI gui(srv);
    gui.show();
    return app.exec();
}
