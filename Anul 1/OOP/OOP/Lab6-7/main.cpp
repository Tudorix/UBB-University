#include <iostream>
#include <bits/stdc++.h>
#include "Exception.h"
#include "Wishlist.h"

#include <QApplication>
#include "GUI.h"

using namespace std;

int main(int argc, char** argv){
    // Init
    vector<Produs> lista;
    vector<Produs> wishlist;

    Wishlist wish(wishlist);
    Repo repo(lista);
    Valid valid;
    Service srv(&repo,valid,&wish);

    srv.addService(45,(char*)"ESP 32",(char*)"Electronice",(char*)"Arduino");
    srv.addService(23,(char*)"Arduino Uno",(char*)"Electronice",(char*)"Arduino");
    srv.addService(68,(char*)"Servo Motor",(char*)"Electronice",(char*)"Gobilda");
    srv.addService(120,(char*)"Servo Motor",(char*)"Electronice",(char*)"Gobilda");

    srv.addService(56,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    srv.addService(34,(char*)"Quad Block",(char*)"Metal",(char*)"Gobilda");
    srv.addService(123,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");

    QApplication app(argc, argv);
    GUI gui(&srv);
    gui.show();

    return app.exec();
}