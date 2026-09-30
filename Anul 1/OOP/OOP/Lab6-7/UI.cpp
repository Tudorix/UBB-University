#include "UI.h"

UI::UI(Service *srv){
    this->service = srv;
}

int readNum(string text){
    cout << "Enter the " << text << " : ";
    int x;
    while(!(cin >> x) || (x < 0)){
        cout << "Try again : ";

        cin.clear();
        cin.ignore(1000, '\n');
    }
    getchar();
    return x;
}

void readString(string text, char *x){
    cout << "Enter the " << text << " : ";
    cin.getline(x,30);
}

void UI::run(){
    cout << "Hello!\n";

    this->service->addService(45,(char*)"ESP 32",(char*)"Electronice",(char*)"Arduino");
    this->service->addService(23,(char*)"Arduino Uno",(char*)"Electronice",(char*)"Arduino");
    this->service->addService(68,(char*)"Servo Motor",(char*)"Electronice",(char*)"Gobilda");
    this->service->addService(120,(char*)"Servo Motor",(char*)"Electronice",(char*)"Gobilda");

    this->service->addService(56,(char*)"Profil U",(char*)"Metal",(char*)"Tetrix");
    this->service->addService(34,(char*)"Quad Block",(char*)"Metal",(char*)"Gobilda");
    this->service->addService(123,(char*)"NeverRest 40",(char*)"Electronice",(char*)"AndyMark");

    bool running = true;
    while(running){
        char com[35];
        cout << "--------\n";
        cout << "1 - Print\n";
        cout << "2 - Add\n";
        cout << "3 - Del\n";
        cout << "4 - Mod\n";
        cout << "5 - Find\n";
        cout << "6 - Filter\n";
        cout << "7 - Sort\n";
        cout << "8 - Raport\n";
        cout << "Wishlist:\n";
        cout << "9 - Empty\n";
        cout << "10 - Print Wishlist\n";
        cout << "11 - Add item to Wishlist\n";
        cout << "12 - Generate Wishlist\n";
        cout << "13 - Export Wishlist\n";
        cout << "15 - Remove Duplicates\n";
        cout << "\n";
        cout << "14 - Undo\n";
        cout << "0 - Exit\n";
        cout << "Enter a command : \n>>>";
        cin.getline(com, 30);
        cout << "\n";
        if(strcmp(com, "1") == 0){
            vector<Produs> out;
            out = this->service->getList();
            for(long unsigned int i = 0; i < out.size(); i++){
                out[i].afiseaza();
            }
        }
        if(strcmp(com, "2") == 0){
            int pret;
            char nume[30];
            char tip[30];
            char producator[30];
            pret = readNum("pret");
            readString("nume",nume);
            readString("tip",tip);
            readString("producator",producator);
            this->service->addService(pret,nume,tip,producator);
        }
        if(strcmp(com, "3") == 0){
            int id;
            id = readNum("id");
            try{
                this->service->delService(id);
                cout << "Produs deleted successfully!\n";
            }catch (const Except& e){
                cout << "Task unsuccessful : " << e.what() << "\n";
            }
        }
        if(strcmp(com, "4") == 0){
            int id;
            id = readNum("id");
            int pret;
            char nume[30];
            char tip[30];
            char producator[30];
            pret = readNum("pret");
            readString("nume",nume);
            readString("tip",tip);
            readString("producator",producator);
            try{
                this->service->modService(id,pret,nume,tip,producator);
                cout << "Produs modified successfully!\n";
            }catch (const Except& e){
                cout << "Task unsuccessful : " << e.what() << "\n";
            }
        }
        if(strcmp(com, "5") == 0){
            int id;
            id = readNum("id");
            int index = this->service->find(id);
            if(index > -1){
                this->service->getList()[index].afiseaza();
            }else{
                cout << "There is no such Produs in the list\n";
            }
        }
        if(strcmp(com, "6") == 0){
            cout << "1 - Nume\n";
            cout << "2 - Tip\n";
            cout << "3 - Producator\n";
            int mode;
            mode = readNum("mode");
            if(mode >= 1 && mode <= 3){
                vector<Produs> out;
                char criteria[30];
                try{
                    readString("criteria", criteria);
                    out = this->service->filter(mode,criteria);
                    for(long unsigned int i = 0; i < out.size(); i++){
                        out[i].afiseaza();
                    }
                }catch (const Except& e){
                    cout << "Task unsuccessful : " << e.what() << "\n";
                }
            }else{
                cout << "Invalid mode! \n";
            }
        }if(strcmp(com, "7") == 0){
            cout << "1 - Nume\n";
            cout << "2 - Pret\n";
            cout << "3 - Nume+Pret\n";
            int mode;
            mode = readNum("mode");
            if(mode >= 1 && mode <= 3){
                vector<Produs> out;
                try{
                    int dir;
                    cout << "0 - Ascending\n";
                    cout << "Else - Descending\n";
                    dir = readNum("direction");
                    out = this->service->sort(mode,dir);
                    for(long unsigned int i = 0; i < out.size(); i++){
                        out[i].afiseaza();
                    }
                }catch (const Except& e){
                    cout << "Task unsuccessful : " << e.what() << "\n";
                }   
            }else{
                cout << "Invalid mode! \n";
            }
            cout << "\n";
        }
        if(strcmp(com, "8") == 0){
            cout << "1 - Nume\n";
            cout << "2 - Tip\n";
            cout << "3 - Producator\n";
            int mode;
            mode = readNum("mode");
            if(mode >= 1 && mode <= 3){
                char criteria[30];
                try{
                    readString("criteria", criteria);
                    float percentage = this->service->raport(mode,criteria);
                    cout << percentage << " - \n";
                    percentage *= 100;
                    cout << " ---- Graphic ---- \n\n";
                    for(int i = 0; i < percentage; i++){
                        cout << "#";
                    }
                    cout << " = "<< percentage << "%  -> " << criteria << "\n\n";
                    for(int i = percentage + 1; i <= 100; i++){
                        cout << "#";
                    }
                    cout << " = "<< 100 - percentage << "%   -> other\n\n";
                }catch (const Except& e){
                    cout << "Task unsuccessful : " << e.what() << "\n";
                }
            }else{
                cout << "Invalid mode! \n";
            }
        }
        if(strcmp(com, "9") == 0){
            this->service->empty();
        }
        if(strcmp(com, "10") == 0){
            vector<Produs> out;
            out = this->service->getWish();
            for(long unsigned int i = 0; i < out.size(); i++){
                out[i].afiseaza();
            }
        }
        if(strcmp(com, "11") == 0){
            int id = readNum("ID");
            try{
                this->service->addWish(id);
            }catch(const Except &e){
                cout << "Task unsuccessful : " << e.what() << "\n";
            }
        }
        if(strcmp(com, "12") == 0){
            int nr = readNum("number of elements");
            try{
                this->service->generateWish(nr);
            }catch(const Except &e){
                cout << "Task unsuccessful : " << e.what() << "\n";
            }
        }
        if(strcmp(com, "13") == 0){
            char nume[35];
            readString("nume",nume);
            this->service->exportWishlist(nume);
        }
        if(strcmp(com, "14") == 0){
            try{
                this->service->undo();
                cout << "Undo successful!\n";
            }catch(const Except &e){
                cout << "Task unsuccessful : " << e.what() << "\n";
            }
        }
        if(strcmp(com, "15") == 0){
            this->service->removeDuplicates();
            cout << "Duplicates removed successfully!\n";
        }
        if(strcmp(com, "0") == 0){
            cout << "Goodbye!\n";
            running = false;
        }
    }
}