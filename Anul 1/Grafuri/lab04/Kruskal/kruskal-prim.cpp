#include <bits/stdc++.h>
using namespace std;

struct Muchie {
    int x, y, cost;
};

/// ---------- KRUSKAL ----------

int parent[105];

int radacina(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = radacina(parent[x]);
}

bool uneste(int x, int y) {
    int rx = radacina(x);
    int ry = radacina(y);

    if (rx == ry)
        return false;

    parent[ry] = rx;
    return true;
}

void Kruskal() {
    int n, m;
    cin >> n >> m;

    vector<Muchie> muchii;

    for (int i = 0; i < m; i++) {
        Muchie e;
        cin >> e.x >> e.y >> e.cost;
        muchii.push_back(e);
    }

    sort(muchii.begin(), muchii.end(), [](Muchie a, Muchie b) {
        return a.cost < b.cost;
    });

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int costTotal = 0;
    vector<Muchie> sol;

    for (auto e : muchii) {
        if (uneste(e.x, e.y)) {
            sol.push_back(e);
            costTotal += e.cost;
        }
    }

    cout << costTotal << '\n';

    for (auto e : sol)
        cout << e.x << " " << e.y << '\n';
}

/// ---------- PRIM ----------

const int INF = 1e9;

void Prim() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost});
    }

    vector<int> viz(n + 1, 0);
    vector<int> cost(n + 1, INF);
    vector<int> tata(n + 1, 0);

    cost[1] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 1});

    while (!pq.empty()) {
        int nod = pq.top().second;
        pq.pop();

        if (viz[nod])
            continue;

        viz[nod] = 1;

        for (auto vecin : adj[nod]) {
            int v = vecin.first;
            int c = vecin.second;

            if (!viz[v] && c < cost[v]) {
                cost[v] = c;
                tata[v] = nod;
                pq.push({cost[v], v});
            }
        }
    }

    int costTotal = 0;

    for (int i = 1; i <= n; i++)
        costTotal += cost[i];

    cout << costTotal << '\n';

    for (int i = 2; i <= n; i++)
        cout << tata[i] << " " << i << '\n';
}

int main() {
    int cmd;
    cin >> cmd;

    if (cmd == 1)
        Kruskal();
    else
        Prim();

    return 0;
}