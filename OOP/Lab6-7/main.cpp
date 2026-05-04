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

    QApplication app(argc, argv);
    GUI gui(&srv);
    gui.show();

    return app.exec();
}