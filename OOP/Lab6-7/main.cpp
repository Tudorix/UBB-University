#include <iostream>
#include "UI.h"
#include <bits/stdc++.h>
#include "Exception.h"
#include "Wishlist.h"

using namespace std;

int main(){
    // Init
    vector<Produs> lista;
    vector<Produs> wishlist;

    Wishlist wish(wishlist);
    Repo repo(lista);
    Valid valid;
    Service srv(&repo,valid,&wish);

    UI console(&srv);
    console.run();

    return 0;
}