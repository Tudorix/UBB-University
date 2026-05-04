#include <bits/stdc++.h>
using namespace std;

struct Muchie {
    int x, y, cost;
};

int parent[100005], rang[100005];

int findRoot(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]); // compresie drum
}

bool unite(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);

    if (ra == rb)
        return false; // ar forma ciclu

    if (rang[ra] < rang[rb])
        parent[ra] = rb;
    else if (rang[ra] > rang[rb])
        parent[rb] = ra;
    else {
        parent[rb] = ra;
        rang[ra]++;
    }

    return true;
}

ifstream fin("in.txt");

int main() {
    int n, m;
    fin >> n >> m;

    vector<Muchie> muchii(m);

    for (int i = 0; i < m; i++) {
        fin >> muchii[i].x >> muchii[i].y >> muchii[i].cost;
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rang[i] = 0;
    }

    sort(muchii.begin(), muchii.end(), [](Muchie a, Muchie b) {
        return a.cost < b.cost;
    });

    int costTotal = 0;
    vector<Muchie> apm;

    for (auto e : muchii) {
        if (unite(e.x, e.y)) {
            apm.push_back(e);
            costTotal += e.cost;
        }
    }

    cout << "Cost total: " << costTotal << '\n';
    cout << "Muchii APM:\n";

    for (auto e : apm) {
        cout << e.x << " " << e.y<< '\n';
    }

    return 0;
}