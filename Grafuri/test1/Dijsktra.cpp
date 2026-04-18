#include <iostream>
using namespace std;

const int MAXN = 105;
const int INF = 1000000000;

int cost[MAXN][MAXN];
int d[MAXN];
bool folosit[MAXN];
int n, m;

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        folosit[i] = false;
    }

    d[s] = 0;

    for (int step = 1; step <= n; step++) {
        int x = -1;

        for (int i = 1; i <= n; i++) {
            if (!folosit[i] && (x == -1 || d[i] < d[x])) {
                x = i;
            }
        }

        if (x == -1 || d[x] == INF) {
            break;
        }

        folosit[x] = true;

        for (int y = 1; y <= n; y++) {
            if (cost[x][y] != INF) {
                if (d[y] > d[x] + cost[x][y]) {
                    d[y] = d[x] + cost[x][y];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }

    int x, y, c;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> c;
        cost[x][y] = c;
        // cost[y][x] = c; // decomentezi dacă graful e neorientat
    }

    Dijkstra(1);

    cout << "Distante minime:\n";
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) cout << i << ": INF\n";
        else cout << i << ": " << d[i] << "\n";
    }

    return 0;
}