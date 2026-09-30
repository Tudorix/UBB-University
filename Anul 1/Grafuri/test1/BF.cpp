#include <bits/stdc++.h>

using namespace std;

#define MS 10005
#define INF 999999

struct Muchie
{
    int x, y, c;
};

Muchie a[MS];
int t[MS];
int d[MS];
int n ,m;

void BF(int s){
    d[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int x = a[j].x;
            int y = a[j].y;
            int c = a[j].c;

            if(d[x] != INF && d[y] > d[x] + c){
                d[y] = d[x] + c;
                t[y] = x;
            }
        }
    }
}

int main(){
    int s;
    cin >> n >> m >> s;
    int x,y,c;
    for(int i = 0; i < m; i++){
        cin >> a[i].x >> a[i].y >> a[i].c; 
    }

    for(int i = 0; i < n; i++){
        t[i] = -1;
        d[i] = INF;
    }

    BF(s);

    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}

/*
d[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int x = a[j].x;
            int y = a[j].y;
            int c = a[j].c;

            if(d[x] != INF && (d[y] > d[x] + c)){
                d[y] = d[x] + c;
                t[y] = x;
            }
        }
    }
*/