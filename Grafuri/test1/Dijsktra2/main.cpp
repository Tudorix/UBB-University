#include <bits/stdc++.h>

#define MS 105
#define INF 999999

using namespace std;

int n,m;
double a[MS][MS];
int viz[MS];
double d[MS];
int t[MS];

void Dijsktra(int s){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
        viz[i] = 0;
        t[i] = 0;
    }

    d[s] = 0;

    for(int i = 1; i <= n; i++){
        int x = -1;

        for(int j = 1; j <= n; j++){
            if(viz[j] == 0 && (x == -1 || d[j] < d[x])){
                x = j;
            }
        }

        if(x == -1 || d[x] == INF){
            continue;
        }

        viz[x] = 1;

        for(int j = 1; j <= n; j++){
            if(a[x][j] != INF){
                if(d[j] > d[x] + a[x][j]){
                    d[j] = d[x] + a[x][j];
                    t[j] = x;
                }
            }
        }
    }
}

struct{
    int x,y;
}oras[MS];

int main(){
    cin >> n >> m;

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> oras[i].x >> oras[i].y;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        a[x][y] = (double)sqrt(pow(oras[y].x - oras[x].x , 2) + pow(oras[y].y - oras[x].y , 2));
    }

    int sursa = 1;
    int dest = n;

    Dijsktra(sursa);

    while(dest != 0){
        cout << dest << " ";
        dest = t[dest];
    }
    cout << d[6] << "\n";

    return 0;
}