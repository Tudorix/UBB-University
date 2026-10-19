#include <bits/stdc++.h>

#define MS 105

using namespace std;

int n,m;
int a[MS][MS];
int viz[MS];

void DFS(int k){
    viz[k] = 1;

    for(int i = 1; i <= n; i++){
        if(viz[i] == 0 && a[i][k] == 1){
            a[i][k] = 2;
            a[k][i] = 2;
            DFS(i);
        }
    }
}

int main(){
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    DFS(1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                cout << "NU\n";
                return 0;
            }
        }
    }
    cout << "DA\n";
    return 0;
}