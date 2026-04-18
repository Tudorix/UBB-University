#include <bits/stdc++.h>

using namespace std;

int m , n;
int viz[105];
int a[105][105];

void DFS(int k){
    viz[k] = 1;
    for(int i = 1; i <= n; i++){
        if(viz[i] == 0 && a[k][i] == 1){
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

    cin >> x >> y;
    a[x][y] = 0;
    a[y][x] = 0;

    int k = 0;
    for(int i = 1; i <= n; i++){
        if(viz[i] == 0){
            DFS(i);
            k++;
        }
    }

    if(k > 1){
        cout << "NU\n";
        return 0;
    }
    cout << "DA\n";
    return 0;
}