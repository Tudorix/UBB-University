#include <bits/stdc++.h>

using namespace std;

ifstream fin("graf.txt");
int T[105][105];

void Floyd_Warshall(int n){
    for(int i = 1; i <= n; i++){
        T[i][i] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                T[i][j] = T[i][j] | (T[i][k] & T[k][j]);
            }
        }
    }
}

int main(){
    int n;
    fin >> n;
    
    int x, y;
    while(fin >> x >> y){
        T[x][y] = 1;
    }

    Floyd_Warshall(n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}