//Bellman Ford

struct Edge {
	int u, v, wt;
	Edge(int x, int y, int w) {
		u = x;
		v = y;
		wt = w;
	}
};

vector<int> bellmanFord(int n, int src, vector<Edge> e) {
	vector<int> dist(n, 1e9);
	dist[src] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (auto x : edges) {
			if (dist[x.u] + x.wt < dist[x.v])
				dist[x.v] = dist[x.u] + x.wt;
		}
	}

	for (auto x : edges) {
		if (dist[x.u] + x.wt < dist[x.v]) {
			//negative cycle
			return {};
		}
	}

	return dist;
}