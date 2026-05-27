#include <bits/stdc++.h>
using namespace std;

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

    for (int i = 1; i <= n; i++)
        cout << tata[i] << " ";
    cout << endl;
}

int main() {
    Prim();
    return 0;
}