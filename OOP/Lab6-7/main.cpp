#include <bits/stdc++.h>
#include "UI.h"

using namespace std;

int main(){
    // Init
    vector<Produs> lista;
    Repo repo(lista);
    Valid valid;
    Service srv(&repo,valid);

    UI console(&srv);
    console.run();

    return 0;
}