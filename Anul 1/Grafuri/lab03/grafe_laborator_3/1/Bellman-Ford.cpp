#include <bits/stdc++.h>
#define INF 999999

using namespace std;

queue<pair<int,int>> a[1005];
int g[1005];
int t[1005];

void init(int n, int s){
    for(int i = 1; i <= n; i++){
        g[i] = INF;
        t[i] = -1;
    }
    g[s] = 0;
}

void relax(int v, int u, int k){
    if(g[v] > g[u] + k){
        g[v] = g[u] + k;
        t[v] = u;
    }
}

void Bellman_Ford(int n, int m, int s){
    init(n,s);
    for(int i = 1; i <= n; i++){
        while(!a[i].empty()){
            
        }
    }
}

int main(){
    // Fisiere
    char nume[35];
    cin.getline(nume,30);
    ifstream fin(nume);  
    cin.getline(nume,30);  
    ofstream fout(nume);    

    int sursa, n , m;

    int i , j, k;
    fin >> n >> m >> sursa;
    while(fin >> i >> j >> k){
        a[i].push({j,k});
    }

    Bellman_Ford(n,m,sursa);

    fin.close();
    fout.close();
    return 0;
}