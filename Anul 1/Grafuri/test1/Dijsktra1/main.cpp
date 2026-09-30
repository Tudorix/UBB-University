#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
const int INF = 999999;

int cost[MAX][MAX] = {INF};
int d[MAX];
int viz[MAX];
int n, m;

int t[MAX];

void Dijsktra(int s){
    d[s] = 0;

    for(int i = 1; i <= n; i++){
        int x = -1;

        for(int j = 1; j <= n; j++){
            if(!viz[j] && (x == -1 || d[j] < d[x])){
                x = j;
            }
        }

        if(x == -1 || d[x] == INF){
            continue;
        }

        viz[x] = 1;

        for(int j = 1; j <= n; j++){
            if(cost[x][j] != INF){
                if(d[j] > d[x] + cost[x][j]){
                    d[j] = d[x] + cost[x][j];
                    t[j] = x;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    // Pui pe infinit
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cost[i][j] = INF;
    
    // Pui Diag princip pe 0
    for(int i = 1; i <= n; i++){
        cost[i][i] = 0;
        d[i] = INF;
        viz[i] = 0;
        t[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        cost[x][y] = c;
    }

    int sursa, dest;
    cin >> sursa >> dest;
    //cout << sursa << " " << dest;

    Dijsktra(sursa);

    cout << "Distanta este : " << d[dest] << "\n";
    cout << "Drumul este : ";
    while(dest != 0){
        cout << dest << " ";
        dest = t[dest];
    }
    cout << endl;


    return 0;
}