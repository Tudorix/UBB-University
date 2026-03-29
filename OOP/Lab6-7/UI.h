#pragma once
#include <bits/stdc++.h>
#include "Service.h"

class UI{
    private:
        Service *service;
    public:
        UI(Service *srv);
        void run();
};