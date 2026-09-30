#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

ifstream fin("input.txt");

int a[MAXN][MAXN];
bool viz[MAXN];
int n, m;

void DFS(int s) {
    viz[s] = true;
    cout << s << " ";

    for (int i = 1; i <= n; i++) {
        if (a[s][i] == 1 && !viz[i]) {
            DFS(i);
        }
    }
}

int main() {
    fin >> n >> m;

    int x, y;
    while (fin >> x >> y) {
        a[x][y] = 1;         
        a[y][x] = 1;      // decomentezi dacă graful e neorientat
    }

    for (int i = 1; i <= n; i++) {
        if (!viz[i]) {
            DFS(i);
            cout << "\n";
        }
    }

    return 0;
}