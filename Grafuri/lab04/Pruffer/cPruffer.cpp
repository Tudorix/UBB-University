#include <bits/stdc++.h>

using namespace std;    

ifstream fin("in.txt");

int t[105];
int fii[105];

queue<int> q;

int n;

void cPruffer(){
    for(int k = 0; k < n - 1; k++){
        int frunza = -1;

        for(int i = 0; i < n; i++){
            if(fii[i] == 0){
                frunza = i;
                break;
            }
        }

        int parinte = t[frunza];

        if(parinte != -1)
            q.push(parinte);

        fii[frunza] = -1;

        if(parinte != -1)
            fii[parinte]--;
    }
}
int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> t[i];
        if(t[i] != -1)
            fii[t[i]]++;
    }

    cPruffer();

    cout << q.size() << endl;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;


    return 0;
}