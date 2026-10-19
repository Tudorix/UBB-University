#include <bits/stdc++.h>

using namespace std;

#define MS 100605
#define INF 999999

ifstream fin("1-in.txt");

struct Muchie{
    int x, y, c;
};

int n,m;
Muchie e[MS];
int d[MS];
int t[MS];

void BF(int s){
    d[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int x = e[j].x;
            int y = e[j].y;
            int c = e[j].c;

            if(d[x] != INF && (d[y] > d[x] + c)){
                d[y] = d[x] + c;
                t[y] = x;
            }
        }
    }
}

int main(){
    int s;
    fin >> n >> m >> s;

    for(int i = 0; i < m; i++){
        fin >> e[i].x >> e[i].y >> e[i].c;
    }

    for(int i = 0; i <= n; i++){
        d[i] = INF;
    }

    int dest = -1;
    while(dest < 0 || dest >= n){
        cout << "Dest : ";
        cin >> dest;
    }

    BF(s);

    while(dest != 0){
        cout << dest << " ";
        dest = t[dest];
    }
    cout << endl;
    return 0;
}