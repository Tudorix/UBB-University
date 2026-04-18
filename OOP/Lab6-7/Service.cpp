#include "Service.h"

Service::Service (Repo *repo, Valid valid, Wishlist *wishlist){
    /**
    * Constructor pentru Service
    * 
    * @param repo - Repository
    * @param valid - Validator
    */
    this->repo = repo;
    this->valid = valid;
    this->wish = wishlist;
}

// ##### WISHLIST #####

void Service::empty(){
    this->wish->empty();
}

vector<Produs> Service::getWish(){
    return this->wish->getList();
}

void Service::addWish(int i){
    int verif = this->repo->findById(i);
    if(verif < 0)
        throw Except("There is no Produs with that ID");
    vector<Produs> in = this->getList();
    Produs p;
    for(long unsigned int j = 0 ; j < in.size(); j++){
        if(in[j].getID() == i){
            p = in[j];
            break;
        }
    }
    this->wish->add(p);
}

// #####

vector<Produs> Service::getList(){
    /**
     * Functie care ret. lista de produse
     */
    return this->repo->getList();
}

int Service::genID(){
    vector<Produs> out;
    out = this->getList();
    int nextId = 0;
    int i = 0;
    for(auto p : out){
        if(p.getID() != (int)i){
            return i;
        }
        nextId = p.getID() + 1;
        i++;
    }
    return nextId;
}


float Service::raport(int mode, char field[30]){
    /**
     * Functie de filtrare dupa criteriu
     * 
     * @param mode(int)
     * @param field(string)
     * 
     * @return Lista filtrata
     */

    vector<Produs> out;
    vector<Produs> pl = this->getList();
    if(pl.size() < 1){
        throw Except("Not long enough");
    }

    for(auto p : pl){
        switch (mode)
        {
            case 1:{
                if(strcmp(p.getNume().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
            case 2:{
                if(strcmp(p.getTip().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
            case 3:{
                if(strcmp(p.getProducator().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
    
        }
    }

    return (float)(out.size())/ (float)(pl.size());
}

vector<Produs> Service::filter(int mode, char field[30]){
    /**
     * Functie de filtrare dupa criteriu
     * 
     * @param mode(int)
     * @param field(string)
     * 
     * @return Lista filtrata
     */

    vector<Produs> out;
    vector<Produs> pl = this->getList();
    if(pl.size() < 1){
         throw Except("Not long enough");
    }

    for(auto p : pl){
        switch (mode)
        {
            case 1:{
                if(strcmp(p.getNume().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
            case 2:{
                if(strcmp(p.getTip().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
            case 3:{
                if(strcmp(p.getProducator().c_str(),field) == 0){
                    out.push_back(p);
                }
                break;
            }
    
        }
    }
    return out;
}


vector<Produs> Service::sort(int mode, int dir){
    /**
     * Functie de sortare dupa criteriu
     * 
     * @param mode(int)
     * 
     * @return Lista sortata
     */

    vector<Produs> out = this->getList();
    if(out.size() < 1){
         throw Except("Not long enough");
    }

    bool check = false;
    do{
        check = false;
        for(long unsigned int i = 0; i < out.size() - 1;i++){
            switch (mode)
            {
                case 1:{
                    if(dir == 0){
                        if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) > 0){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }
                    }else{
                        if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) < 0){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }
                    }
                    break;
                }
                case 2:{
                    if(dir == 0){
                        if(out[i].getPret() > out[i + 1].getPret()){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }
                    }else{
                        if(out[i].getPret() < out[i + 1].getPret()){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }
                    }
                    break;
                }
                case 3:{
                    if(dir == 0){
                        if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) > 0){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }else if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) == 0){
                            if(out[i].getPret() > out[i + 1].getPret()){
                                check = true;
                                Produs aux = out[i];
                                out[i] = out[i + 1];
                                out[i + 1] = aux;
                            }
                        }
                    }else{
                        if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) < 0){
                            check = true;
                            Produs aux = out[i];
                            out[i] = out[i + 1];
                            out[i + 1] = aux;
                        }else if(strcmp(out[i].getNume().c_str(),out[i+1].getNume().c_str()) == 0){
                            if(out[i].getPret() < out[i + 1].getPret()){
                                check = true;
                                Produs aux = out[i];
                                out[i] = out[i + 1];
                                out[i + 1] = aux;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }while(check);
    return out;
}

int Service::find(int id){
    /**
     * Cautare Produs dupa ID
     * 
     * @param id(int)
     * 
     * @return index Produs cautat
     */

    int index = this->repo->findById(id);
    return index;
}

void Service::addService(int pret, char nume[30], char tip[30], char producator[30], int id){
    /**
     * Functie care adauga produs
     * 
     * @param pret(int) - pretul
     * @param nume(string) - numele
     * @param tip(string) - tipul
     * @param producator(string) - producatorul
     */

    if(id == -1){
        id = this->genID();
    }

    Produs p(id, pret,nume,tip,producator);
    this->repo->addRepo(p);
}

void Service::delService(int id){
    /**
     * Functie care sterge produs din lista
     * 
     * @param id(int)
     */

    int verif = this->repo->findById(id);
    if(verif < 0)
        throw Except("There is no Produs with that ID");
    this->repo->delRepo(verif);
}

void Service::modService(int id,int pret, char nume[30], char tip[30], char producator[30]){
    /**
     * Functie care modifica un produs
     * 
     * @param id(int)
     * @param pret(int) - pretul
     * @param nume(string) - numele
     * @param tip(string) - tipul
     * @param producator(string) - producatorul
     */

    try{
        this->delService(id);
        this->addService(pret,nume,tip,producator,id);
    }catch (const char* e){
        throw Except("There is no Produs with that ID");
    }
}