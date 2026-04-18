#include <iostream>
using namespace std;

const int MAXN = 105;
const int MAXM = 10005;
const int INF = 1000000000;

struct Muchie {
    int x, y, c;
};

Muchie e[MAXM];
int d[MAXN];
int n, m;

bool BellmanFord(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            int x = e[j].x;
            int y = e[j].y;
            int c = e[j].c;

            if (d[x] != INF && d[y] > d[x] + c) {
                d[y] = d[x] + c;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        int x = e[j].x;
        int y = e[j].y;
        int c = e[j].c;

        if (d[x] != INF && d[y] > d[x] + c) {
            return false; // există ciclu negativ
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].c;
    }

    if (!BellmanFord(1)) {
        cout << "Exista ciclu negativ\n";
    } else {
        cout << "Distante minime:\n";
        for (int i = 1; i <= n; i++) {
            if (d[i] == INF) cout << i << ": INF\n";
            else cout << i << ": " << d[i] << "\n";
        }
    }

    return 0;
}