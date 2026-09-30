#include <bits/stdc++.h>

using namespace std;

#define MS 10005
#define INF 999999
int n , m, s;
int a[MS][MS];
int viz[MS];
int d[MS];
int t[MS];

void Djisktra(int s){
    d[s] = 0;

    for(int i = 0; i < n; i++){
        int x = -1;

        for(int j = 1; i <= n; j++){
            if(viz[j] == 0 && (x == -1 || d[j] < d[x])){
                x = j;
            }
        }

        if(x == -1 || d[x] == INF){
            break;
        }

        viz[x] = 1;

        for(int j = 1; j <= n; j++){
            if(a[j][x] != INF){
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
    int x, y ,c;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = INF;
        }
        a[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y >> c;
        a[x][y] = c;
    }

    for(int i = 0; i < n; i++){
        viz[i] = 0;
        d[i] = INF;
        t[i] = -1;
    }

    Djisktra(s);

    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
d[s] = 0;

    for(int i = 0; i < n; i++){
        int x = -1;

        for(int j = 0; j < n; j++){
            if(viz[j] == 0 && (x == -1 || d[j] < d[x])){
                x = j;
            }
        }

        if(x == -1 || d[x] == INF){
            break;
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
*/