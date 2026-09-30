#include <bits/stdc++.h>

using namespace std;

ifstream fin("graf.txt");
queue<int> a[100];
queue<int> q;
queue<int> niv;
queue<int> last_niv;
int viz[100];

void BFS(int s, int n){
    int c = 0;
    q.push(s);
    while(!q.empty()){
        niv = q;
        while(!q.empty()) q.pop();
        cout << "Nivel " << c << ": ";
        while(!niv.empty()){
            int nod = niv.front();
            while(!a[nod].empty()){
                if(viz[a[nod].front()] == 0){
                    q.push(a[nod].front());
                }
                a[nod].pop();
            }
            niv.pop();
            if(viz[nod] == 0){
                cout << nod << " ";
                viz[nod] = 1;
                n--;
            }
        }
        c++;
        cout << endl;
    }
}

int main(){
    int n;
    fin >> n;
    int x, y;
    while(fin >> x >> y){
        a[x].push(y);
    }

    cout << "Sursa: ";
    int s;
    cin >> s;

    BFS(s, n + 1);
    return 0;
}