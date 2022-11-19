//for weighted graph

vi dis;

void dijkstra(int s, int n)
{
    dis.assign(n, INT_MAX);
    priority_queue<pii, vii, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dist = pq.top().F;
        pq.pop();
        if(dis[u] < dist) //this will not lead to any shortest path (invalid entry in pq)
           continue;
        for (auto &v : G[u]) {
            if (dis[u] + v.S < dis[v.F]) {
                dis[v.F] = dis[u] + v.S;
                pq.push({dis[v.F], v.F});
            }
        }
    }
}


//for unweighted graph

vi dis;

void dijkstra(int s, int n)
{
    dis.assign(n, INT_MAX);
    priority_queue<pii, vii, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dist = pq.top().F;
        pq.pop();
        if(dis[u] < dist) //this will not lead to any shortest path (invalid entry in pq)
           continue;
        for (auto &v : G[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                pq.push({dis[v], v});
            }
        }
    }
}
