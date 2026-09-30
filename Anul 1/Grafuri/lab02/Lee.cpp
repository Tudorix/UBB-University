#include <bits/stdc++.h>

using namespace std;

ifstream fin("labirint_2.txt");

int dist[1005][1005];
char m[1005][1005];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int>> q;

void Lee(int h, int w, int xS, int yS){
    while(!q.empty()) q.pop();

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            dist[i][j] = -1;
        }
    }

    dist[xS][yS] = 0;
    q.push({xS,yS});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();

        int x = node.first;
        int y = node.second;

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < w && ny >= 0 && ny < h){
                if(dist[nx][ny] == -1 && (m[nx][ny] == ' ' || m[nx][ny] == 'F')){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void reconstruct(int xF, int yF){
    while(dist[xF][yF] > 0){
        for(int k = 0; k < 4; k++){
            int nx = xF + dx[k];
            int ny = yF + dy[k];
            if(dist[nx][ny] == dist[xF][yF] - 1){
                xF = nx;
                yF = ny;
                m[nx][ny] = '#';
                break;
            }
        }
    }
}

int main(){
    int w,h;
    char x;
    int i = 0;
    int j = 0;
    string line;

    int xS , yS;
    int xF , yF;

    while(getline(fin,line)){
        w = line.length();
        for(int k = 0; k < line.length(); k++){
            m[i][k] = line[k];
            if(m[i][k] == 'S'){
                xS = i;
                yS = k;
            }
            if(m[i][k] == 'F'){
                xF = i;
                yF = k;
            }
        }
        i++;
    }
    h = i;

    cout << "Height: " << h << " ; Width: " << w << "\nSursa: " << xS << " , " << yS << endl;

    Lee(w,h,xS,yS);

    if(dist[xF][yF] != -1){
        cout << "Avem solutie\n";
        reconstruct(xF,yF);
        for(int i = 0; i < h;i++){
            for(int j = 0; j < w;j++){
                cout << m[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}