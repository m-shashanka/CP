//Prim's

int spanningTree(int v, vector<pair<int, int>> G[])
{
    vector<int> key(v, INT_MAX), included(v), parent(v);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        included[u] = true;
        for (auto v : G[u]) {
            if (!included[v.first] && v.second < key[v.first]) {
                parent[v.first] = u;
                key[v.first] = v.second;
                pq.push({v.second, v.first});
            }
        }
    }

    //selected edges
    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";

    int cost = accumulate(key.begin(), key.end(), 0);
    return cost;
}
