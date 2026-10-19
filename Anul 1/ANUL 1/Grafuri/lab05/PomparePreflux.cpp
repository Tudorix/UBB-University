#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1005;

int n, m;
int c[NMAX][NMAX];
int f[NMAX][NMAX];
int h[NMAX], exces[NMAX];

void push(int x, int y) {
    int trimis = min(exces[x], c[x][y] - f[x][y]);

    f[x][y] += trimis;
    f[y][x] -= trimis;

    exces[x] -= trimis;
    exces[y] += trimis;
}

void relabel(int x) {
    int minim = INT_MAX;

    for (int y = 0; y < n; y++) {
        if (c[x][y] - f[x][y] > 0) {
            minim = min(minim, h[y]);
        }
    }

    if (minim != INT_MAX) {
        h[x] = minim + 1;
    }
}

int fluxMaxim(int s, int t) {
    h[s] = n;

    for (int y = 0; y < n; y++) {
        if (c[s][y] > 0) {
            f[s][y] = c[s][y];
            f[y][s] = -c[s][y];

            exces[y] = c[s][y];
            exces[s] -= c[s][y];
        }
    }

    bool schimbat = true;

    while (schimbat) {
        schimbat = false;

        for (int x = 0; x < n; x++) {
            if (x == s || x == t || exces[x] == 0)
                continue;

            bool amPompat = false;

            for (int y = 0; y < n && exces[x] > 0; y++) {
                if (c[x][y] - f[x][y] > 0 && h[x] == h[y] + 1) {
                    push(x, y);
                    amPompat = true;
                    schimbat = true;
                }
            }

            if (exces[x] > 0 && !amPompat) {
                relabel(x);
                schimbat = true;
            }
        }
    }

    return exces[t];
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        fin >> x >> y >> w;
        c[x][y] += w;
    }

    fout << fluxMaxim(0, n - 1);

    return 0;
}