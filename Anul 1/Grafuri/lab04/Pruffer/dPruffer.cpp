#include <bits/stdc++.h>
using namespace std;

ifstream fin("out.txt");

int t[100], k[100], frecv[100];
bool folosit[100];

int n;

int minim() {
    for(int i = 0; i <= n; i++) {
        if(!folosit[i] && frecv[i] == 0)
            return i;
    }
    return -1;
}

void dPruffer() {
    for(int i = 0; i <= n; i++) {
        t[i] = -1;
        frecv[i] = 0;
        folosit[i] = false;
    }

    for(int i = 0; i < n; i++) {
        frecv[k[i]]++;
    }

    for(int i = 0; i < n; i++) {
        int x = k[i];
        int y = minim();

        t[y] = x;
        folosit[y] = true;

        frecv[x]--;
    }

    int rad = minim();
    t[rad] = -1;
}

int main() {
    fin >> n;

    for(int i = 0; i < n; i++) {
        fin >> k[i];
    }

    dPruffer();

    cout << n + 1 << "\n";

    for(int i = 0; i <= n; i++) {
        cout << t[i] << " ";
    }

    cout << endl;

    return 0;
}