#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<pair<int,int>> adj[100005]; 
int distanta[100005];

void Dijkstra(int start, int n) {
    for (int i = 1; i <= n; i++)
        distanta[i] = INF;

    distanta[start] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start}); // cost, nod

    while (!pq.empty()) {
        int costCurent = pq.top().first;
        int nod = pq.top().second;
        pq.pop();

        if (costCurent != distanta[nod])
            continue;

        for (auto muchie : adj[nod]) {
            int vecin = muchie.first;
            int cost = muchie.second;

            if (distanta[vecin] > distanta[nod] + cost) {
                distanta[vecin] = distanta[nod] + cost;
                pq.push({distanta[vecin], vecin});
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 1; i <= m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        adj[x].push_back({y, cost});
        // adj[y].push_back({x, cost}); // decomentezi dacă graful e neorientat
    }

    Dijkstra(start, n);

    for (int i = 1; i <= n; i++) {
        if (distanta[i] == INF)
            cout << "INF ";
        else
            cout << distanta[i] << " ";
    }

    return 0;
}