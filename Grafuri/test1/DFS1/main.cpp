#include <bits/stdc++.h>

#define MS 105

using namespace std;

int n, m;
int viz[MS];
int a[MS][MS];

void DFS(int k){
    viz[k] = 1;
    for(int i = 1; i <= n; i++){
        if(a[k][i] == 1 && viz[i] == 0){
            DFS(i);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++){
        viz[i] = 0;
    }

    int k = 0;
    for(int i = 1; i <= n; i++){
        if(viz[i] == 0){
            DFS(i);
            k++;
        }
    }

    cout << "Sunt " << k << " grupuri de prieteni.";
    return 0;
}