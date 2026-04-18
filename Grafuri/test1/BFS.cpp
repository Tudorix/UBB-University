#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;

int a[MAXN][MAXN];
bool viz[MAXN];
int distanta[MAXN];
int n, m;

void BFS(int s) {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        viz[i] = false;
        distanta[i] = -1;
    }

    viz[s] = true;
    distanta[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for (int y = 1; y <= n; y++) {
            if (a[x][y] == 1 && !viz[y]) {
                viz[y] = true;
                distanta[y] = distanta[x] + 1;
                q.push(y);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x][y] = 1;
        // a[y][x] = 1; // decomentezi dacă graful e neorientat
    }

    BFS(1);

    cout << "\nDistante:\n";
    for (int i = 1; i <= n; i++) {
        cout << "d[" << i << "] = " << distanta[i] << "\n";
    }

    return 0;
}