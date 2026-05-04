#include <bits/stdc++.h>
using namespace std;

struct Nod {
    char ch;
    int fr;
    int st, dr;
    char minChar;
    bool folosit;
};

vector<Nod> v;

int alegeMinim() {
    int poz = -1;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].folosit) continue;

        if (poz == -1 ||
            v[i].fr < v[poz].fr ||
            (v[i].fr == v[poz].fr && v[i].minChar < v[poz].minChar)) {
            poz = i;
        }
    }

    v[poz].folosit = true;
    return poz;
}

ifstream fin("in.txt");

int main() {
    int n;
    fin >> n;

    int fr[256] = {0};

    for (int i = 0; i < n; i++) {
        char ch;
        int f;

        fin >> ch >> f;
        fr[(unsigned char)ch] = f;
    }

    string biti;
    fin >> biti;

    for (int i = 0; i < 256; i++) {
        if (fr[i] > 0) {
            Nod x;
            x.ch = char(i);
            x.fr = fr[i];
            x.st = x.dr = -1;
            x.minChar = char(i);
            x.folosit = false;
            v.push_back(x);
        }
    }

    while (v.size() > 1) {
        int a = alegeMinim();

        bool exista = false;
        for (auto nod : v)
            if (!nod.folosit)
                exista = true;

        if (!exista) {
            v[a].folosit = false;
            break;
        }

        int b = alegeMinim();

        Nod nou;
        nou.ch = 0;
        nou.fr = v[a].fr + v[b].fr;
        nou.st = a;
        nou.dr = b;
        nou.minChar = min(v[a].minChar, v[b].minChar);
        nou.folosit = false;

        v.push_back(nou);
    }

    int rad = v.size() - 1;

    // caz special: un singur caracter distinct
    if (n == 1) {
        char ch = v[rad].ch;
        for (int i = 0; i < v[rad].fr; i++)
            cout << ch;
        return 0;
    }

    int curent = rad;

    for (char bit : biti) {
        if (bit == '0')
            curent = v[curent].st;
        else
            curent = v[curent].dr;

        if (v[curent].st == -1 && v[curent].dr == -1) {
            cout << v[curent].ch;
            curent = rad;
        }
    }

    cout << endl;

    return 0;
}