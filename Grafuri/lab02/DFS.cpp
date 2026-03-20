#include <bits/stdc++.h>

using namespace std;

queue<int> a[100];
ifstream fin("graf.txt");
int viz[105];

void DFSVisit(int v){
    viz[v] = 1;
    cout << v << " ";
    while(!a[v].empty()){
        if(viz[a[v].front()] == 0){
            DFSVisit(a[v].front());
        }
        a[v].pop();
    }
}

void DFS(int n){
    for(int i = 1; i <= n; i++){
        if(viz[i] == 0){
            DFSVisit(i);
        }
    }
}

int main(){
    int n;
    fin >> n;
    int x,y;
    while(fin >> x >> y){
        a[x].push(y);
    }

    DFS(n);
    cout << endl;
    return 0;
}