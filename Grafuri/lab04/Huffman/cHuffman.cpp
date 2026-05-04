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
map<char, string> cod;

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

void dfs(int nod, string c) {
    if (v[nod].st == -1 && v[nod].dr == -1) {
        if (c == "") c = "0"; // caz special
        cod[v[nod].ch] = c;
        return;
    }

    dfs(v[nod].st, c + "0");
    dfs(v[nod].dr, c + "1");
}

int main() {
    string text;
    getline(cin, text);

    int fr[256] = {0};

    for (char ch : text)
        fr[(unsigned char)ch]++;

    // creez noduri initiale
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

    int n = v.size();

    // construim arborele
    while (true) {
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

    dfs(rad, "");

    // OUTPUT
    cout << n << '\n';

    for (int i = 0; i < 256; i++) {
        if (fr[i] > 0) {
            cout << char(i) << " " << fr[i] << '\n';
        }
    }

    for (char ch : text) {
        cout << cod[ch];
    }
    cout << endl;

    return 0;
}