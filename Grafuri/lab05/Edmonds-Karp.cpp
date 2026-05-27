#include <bits/stdc++.h>
using namespace std;

int n, m;
int cap[1005][1005];
vector<int> g[1005];

int bfs(int s, int t, vector<int>& tata) {
    fill(tata.begin(), tata.end(), -1);

    queue<int> q;
    q.push(s);
    tata[s] = s;

    while (!q.empty()) {
        int nod = q.front();
        q.pop();

        for (int vecin : g[nod]) {
            if (tata[vecin] == -1 && cap[nod][vecin] > 0) {
                tata[vecin] = nod;

                if (vecin == t)
                    return 1;

                q.push(vecin);
            }
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, c;
        fin >> x >> y >> c;

        cap[x][y] += c;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s = 0;
    int t = n - 1;
    int flowMax = 0;

    vector<int> tata(n);

    while (bfs(s, t, tata)) {
        int flow = 1e9;

        int nod = t;
        while (nod != s) {
            int p = tata[nod];
            flow = min(flow, cap[p][nod]);
            nod = p;
        }

        nod = t;
        while (nod != s) {
            int p = tata[nod];

            cap[p][nod] -= flow;
            cap[nod][p] += flow;

            nod = p;
        }

        flowMax += flow;
    }

    fout << flowMax;

    return 0;
}