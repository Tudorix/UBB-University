#include "Service.h"
#include "Repo.h"
#include <QApplication>
#include "Valid.h"
#include "test.h"

#include "GUI.h"


int main(int argc, char *argv[]) {
    // De test
    string tfn = "/home/tudorix/UBB/UBB-University/OOP/SubSim/save_test.txt";
    Repo trepo(tfn);
    Valid tvalid(trepo);
    Service tservice(trepo, tvalid);
    test test(&tservice,&trepo);

    // Main
    string fn = "/home/tudorix/UBB/UBB-University/OOP/SubSim/save.txt";
    Repo repo(fn);
    Valid valid(repo);
    Service service(repo, valid);

    QApplication app(argc, argv);
    GUI gui(&service);
    gui.show();
    return app.exec();
}
