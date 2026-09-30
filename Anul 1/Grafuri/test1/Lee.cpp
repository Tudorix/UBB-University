#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;

int a[MAXN][MAXN];
int distanta[MAXN][MAXN];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Lee(int xs, int ys) {
    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            distanta[i][j] = -1;
        }
    }

    distanta[xs][ys] = 0;
    q.push({xs, ys});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= n &&
                ny >= 1 && ny <= m &&
                a[nx][ny] == 0 &&
                distanta[nx][ny] == -1) {
                distanta[nx][ny] = distanta[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int xs, ys;
    cin >> xs >> ys;

    Lee(xs, ys);

    cout << "Matricea distantelor:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << distanta[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}