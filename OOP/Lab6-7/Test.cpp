#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include "Service.h"
#include "Repo.h"
#include "Valid.h"
#include <assert.h>

using namespace std;

void testExtCase(Service *s){
    assert(s->getList().size() == 0);
    vector<Produs> rez;
    try{
        rez = s->filter(1, (char*)"Core Hex Motor");
    }catch(const Except& e){}

    try{
        rez = s->sort(3, 0);
    }catch(const Except& e){}

    try{
        s->modService(100, 999, (char*)"Core Hex Motor", (char*)"Motoare", (char*)"REV");
    }catch (const Except& e){}
}

void testAdd(Service *s){
    assert(s->getList().size() == 0);
    s->addService(56,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    s->addService(34,(char*)"Quad Block",(char*)"Metal",(char*)"Gobilda");
    s->addService(123,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");
    assert(s->getList().size() == 3);
    assert(s->getList()[0].getID() == 0);
    assert(s->getList()[1].getID() == 1);
    assert(s->getList()[2].getID() == 2);
}

void testDel(Service *s){
    assert(s->getList().size() == 3);
    s->delService(0);
    assert(s->getList().size() == 2);
    try{
        s->delService(0);
    }catch(const Except& e){}
    assert(s->getList().size() == 2);
}

void testMod(Service *s){
    assert(s->getList().size() == 2);

    // inainte de modificare
    int pos = s->find(1);
    assert(pos >= 0);
    assert(s->getList()[pos].getPret() == 34);
    assert(strcmp(s->getList()[pos].getNume().c_str(), "Quad Block") == 0);
    assert(strcmp(s->getList()[pos].getTip().c_str(), "Metal") == 0);
    assert(strcmp(s->getList()[pos].getProducator().c_str(), "Gobilda") == 0);

    // modificare
    s->modService(1, 999, (char*)"Core Hex Motor", (char*)"Motoare", (char*)"REV");

    // dupa modificare
    pos = s->find(1);
    assert(pos >= 0);
    assert(s->getList()[pos].getID() == 1);
    assert(s->getList()[pos].getPret() == 999);
    assert(strcmp(s->getList()[pos].getNume().c_str(), "Core Hex Motor") == 0);
    assert(strcmp(s->getList()[pos].getTip().c_str(), "Motoare") == 0);
    assert(strcmp(s->getList()[pos].getProducator().c_str(), "REV") == 0);

    assert(s->getList().size() == 2);
}

void testFind(Service *s){
    // dupa testele anterioare ar trebui sa existe id 1 si 2
    int pos1 = s->find(1);
    int pos2 = s->find(2);
    int pos0 = s->find(0);

    assert(pos1 >= 0);
    assert(pos2 >= 0);
    assert(pos0 < 0);

    assert(s->getList()[pos1].getID() == 1);
    assert(s->getList()[pos2].getID() == 2);
}

void testFilter(Service *s){
    vector<Produs> rez;

    // filtrare dupa nume
    rez = s->filter(1, (char*)"Core Hex Motor");
    assert(rez.size() == 1);
    assert(rez[0].getID() == 1);

    // filtrare dupa tip
    rez = s->filter(2, (char*)"Electronice");
    assert(rez.size() == 1);
    assert(rez[0].getID() == 2);

    // filtrare dupa producator
    rez = s->filter(3, (char*)"REV");
    assert(rez.size() == 1);
    assert(rez[0].getID() == 1);

    // caz fara rezultate
    rez = s->filter(1, (char*)"Nu exista");
    assert(rez.size() == 0);
}

void testSort(Service *s){
    vector<Produs> rez;

    // sortare dupa nume crescator
    rez = s->sort(1, 0);
    assert(rez.size() == 2);
    assert(strcmp(rez[0].getNume().c_str(), "Core Hex Motor") == 0);
    assert(strcmp(rez[1].getNume().c_str(), "NeverRest 40") == 0);

    // sortare dupa nume descrescator
    rez = s->sort(1, 1);
    assert(rez.size() == 2);
    assert(strcmp(rez[0].getNume().c_str(), "NeverRest 40") == 0);
    assert(strcmp(rez[1].getNume().c_str(), "Core Hex Motor") == 0);

    // sortare dupa pret crescator
    rez = s->sort(2, 1);
    rez = s->sort(2, 0);
    assert(rez.size() == 2);
    assert(rez[0].getPret() == 123);
    assert(rez[1].getPret() == 999);

    // sortare dupa pret descrescator
    rez = s->sort(3, 1);
    rez = s->sort(2, 1);
    assert(rez.size() == 2);
    assert(rez[0].getPret() == 999);
    assert(rez[1].getPret() == 123);

    // sortare dupa nume + pret
    rez = s->sort(3, 1);
    rez = s->sort(3, 0);
    assert(rez.size() == 2);
    assert(strcmp(rez[0].getNume().c_str(), "Core Hex Motor") == 0);
    assert(strcmp(rez[1].getNume().c_str(), "NeverRest 40") == 0);

    s->addService(54,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    s->addService(32,(char*)"Quad Block",(char*)"Metal",(char*)"Gobilda");
    s->addService(121,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");
    s->addService(34,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    s->addService(50,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    s->addService(30,(char*)"Quad Block",(char*)"Metal",(char*)"Gobilda");
    s->addService(13,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");
    s->addService(9,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");
    rez = s->sort(3, 1);
    rez = s->sort(3, 0);
    rez = s->sort(1, 1);
    rez = s->sort(1, 0);
    rez = s->sort(2, 1);
    rez = s->sort(2, 0);
}

void testWishAdd(Service *s){
    s->empty();
    assert(s->getWish().size() == 0);

    s->addWish(1);
    assert(s->getWish().size() == 1);
    assert(s->getWish()[0].getID() == 1);

    s->addWish(2);
    assert(s->getWish().size() == 2);
    assert(s->getWish()[1].getID() == 2);

    try{
        s->addWish(999);
        assert(false);
    }catch(const Except& e){
        assert(true);
    }catch(...){
        assert(false);
    }
}

void testWishGet(Service *s){
    s->empty();
    assert(s->getWish().size() == 0);

    s->addWish(1);
    s->addWish(2);

    vector<Produs> w = s->getWish();
    assert(w.size() == 2);
    assert(w[0].getID() == 1);
    assert(w[1].getID() == 2);
}

void testWishEmpty(Service *s){
    s->addWish(1);
    s->addWish(2);
    assert(s->getWish().size() >= 2);

    s->empty();
    assert(s->getWish().size() == 0);
}

void testWishGenerate(Service *s){
    s->empty();
    assert(s->getWish().size() == 0);

    srand(1);
    s->generateWish(3);

    assert(s->getWish().size() == 3);

    vector<Produs> all = s->getList();
    vector<Produs> wish = s->getWish();

    for(long unsigned int i = 0; i < wish.size(); i++){
        bool found = false;
        for(long unsigned int j = 0; j < all.size(); j++){
            if(wish[i].getID() == all[j].getID()){
                found = true;
                break;
            }
        }
        assert(found);
    }
}

void testWishExport(Service *s){
    s->empty();
    s->addWish(1);
    s->addWish(2);

    try{
        s->exportWishlist((char*)"wishlist_test.html");
        assert(true);
    }catch(...){
        assert(false);
    }
}

int main(){
    vector<Produs> lista;
    vector<Produs> wishlist;

    Wishlist wish(wishlist);
    Repo repo(lista);
    Valid valid;
    Service srv(&repo,valid,&wish);

    // Run Tests
    testExtCase(&srv);
    testAdd(&srv);
    testDel(&srv);
    testMod(&srv);
    testFind(&srv);
    testFilter(&srv);
    testSort(&srv);

    // Wishlist tests
    testWishAdd(&srv);
    testWishGet(&srv);
    testWishEmpty(&srv);
    testWishGenerate(&srv);
    testWishExport(&srv);

    cout << "Finished Tests!\n";
    return 0;
}