#include <bits/stdc++.h>

using namespace std;

#define INF 999999

queue<int> q;
queue<int> a[100];
queue<int> aux;
int l[100];
int p[100];

ifstream fin("graf.txt");

void moore(int n,int s){
    for(int i = 1; i <= n; i++){
        l[i] = INF;
        p[i] = 0;
    }
    l[s] = 0;
    q.push(s);
    while(q.size() > 0){
        int x;
        x = q.front();
        q.pop();
        aux = a[x];
        while(aux.size() > 0){
            int y = aux.front();
            aux.pop();
            if(l[y] == INF){
                l[y] = l[x] + 1;
                p[y] = x;
                q.push(y);
            }
        }
    }
}

int main(){
    int n;
    fin >> n;
    
    int x, y;
    while(fin >> x >> y){
        a[x].push(y);
    }

    //Nodurile Sursa si destinatie
    int s, d;
    cin >> s >> d;

    moore(n,s);

    cout << "Lungimi:\n";
    for(int i = 1; i <= n; i++){
        cout << l[i] << " ";
    }
    cout << "\nParinti:\n";
    for(int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }
    cout << "\n";

    int nod = d;
    cout << "Cel mai scurt drum de la " << d << " la " << s << " este:\n";
    while(nod != s){
        cout << nod << " ";
        nod = p[nod];
    }
    cout << nod << " ";
    cout << endl;

    return 0;
}