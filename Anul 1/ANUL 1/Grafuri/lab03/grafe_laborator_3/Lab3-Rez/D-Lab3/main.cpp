#include <bits/stdc++.h>

#define MS 10005
#define INF 999999

using namespace std;

int n, m , s;
int a[MS][MS];
int viz[MS];
int t[MS];
int d[MS];

void Djisktra(int s){
    for(int i = 0; i < n; i++){
        d[i] = INF;
        viz[i] = 0;
        t[i] = 0;
    }

    d[s] = 0;

    for(int i = 1; i <= n; i++){
        int x = -1;

        for(int j = 0; j < n; j++){
            if(viz[j] == 0 && (x == -1 || d[j] < d[x])){
                x = j;
            }
        }

        if(x == -1 || d[x] == INF){
            continue;
        }

        viz[x] = 1;

        for(int j = 0; j < n; j++){
            if(a[x][j] != INF){
                if(d[j] > d[x] + a[x][j]){
                    d[j] = d[x] + a[x][j];
                    t[j] = x;
                }
            }
        }
    }
}

int main(){

    cin >> n >> m >> s;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = INF;
        }
        a[i][i] = 0;
    }

    int x, y, c;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> c;
        a[x][y] = c;
    }

    Djisktra(s);

    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
    cout << "\n";

    return 0;
}