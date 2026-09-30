#pragma once
#include <bits/stdc++.h>
#include "Service.h"
#include "Exception.h"

using namespace std;
class UI{
    private:
        Service *service;
    public:
        UI(Service *srv);
        void run();
};