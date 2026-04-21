#include <bits/stdc++.h>

using namespace std;

#define INF 999999
#define MS 10005

struct Muchie{
    int x,y,c;
};

int n,m;

Muchie e[MS];
int h[MS];

int a[MS][MS];
int viz[MS];
int d[MS];

void BF(int s){
    h[s] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m + n; j++){
            int x = e[j].x;
            int y = e[j].y;
            int c = e[j].c;

            if(h[x] != INF && (h[y] > h[x] + c)){
                h[y] = h[x] + c;
            }
        }
    }

    for(int j = 0; j < m + n; j++){
            int x = e[j].x;
            int y = e[j].y;
            int c = e[j].c;

            if(h[x] != INF && (h[y] > h[x] + c)){
                cout << "-1"; exit(0);
            }
        }
}

void D(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            d[i] = INF;
            viz[i] = -1;
        }

        d[k] = 0;

        for(int i = 0; i < n; i++){
            int x = -1;

            for(int j = 0; j < n; j++){
                if(viz[j] == -1 && (x == -1 || d[j] < d[x])){
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
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << d[i] - h[k] + h[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> e[i].x >> e[i].y >> e[i].c;
    }

    int i = m;
    int k = 0;
    while(i < m + n){
        e[i].x = n;
        e[i].y = k;
        e[i].c = 0;
        k++;
        i++;
    }

    for(int i = 0; i < n; i++){
        h[i] = INF;
    }

    cout << endl;

    BF(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = INF;
        }
        a[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int cost = e[i].c + h[e[i].x] - h[e[i].y];
        a[e[i].x][e[i].y] = cost;
        cout << e[i].x << " " << e[i].y << " " << cost << "\n";
    }

    D();
    return 0;
}