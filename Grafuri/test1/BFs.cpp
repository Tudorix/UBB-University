#include <bits/stdc++.h>

using namespace std;

#define MS 10005

int n,m;
int a[MS][MS];
int viz[MS];

void BFS(int s){
    viz[s] = 1;
    queue<int> q;

    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        cout << k << " ";

        for(int i = 1; i <= n; i++){
            if(a[k][i] == 1 && viz[i] == 0){
                q.push(i);
                viz[i] = 1;
            }
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

    BFS(1);

    return 0;
}
