#include <bits/stdc++.h>
using namespace std;

ifstream fin("p3.in");
ofstream fout("p3.out");

struct Muchie {
    int vecin;
    int id;
};

vector<Muchie> g[100005];
vector<int> sol;
bool fol[500005];

int V, E;

void euler(int nod) {
    while (!g[nod].empty()) {

        Muchie m = g[nod].back();
        g[nod].pop_back();

        if (fol[m.id])
            continue;

        fol[m.id] = true;

        euler(m.vecin);
    }

    sol.push_back(nod);
}

int main() {

    fin >> V >> E;

    for (int i = 0; i < E; i++) {
        int x, y;
        fin >> x >> y;

        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }

    euler(0);

    reverse(sol.begin(), sol.end());

    for (int x : sol)
        fout << x << " ";

    return 0;
}