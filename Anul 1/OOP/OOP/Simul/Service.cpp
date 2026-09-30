//
// Created by tudorix on 20.05.2026.
//

#include "Service.h"

vector<Produs>& Service::getAll() {
    this->repo.readFromFile();
    return this->repo.getAll();
}