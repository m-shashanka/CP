bool bipartite = true;

vi color(N, -1);

void dfs(int u) {
	for (auto v : G[u]) {
		if (color[v] == -1) {
			color[v] = color[u] ^ 1;
			dfs(v);
		}
		else if (color[v] == color[u]) {
			bipartite = false;
			return;
		}
	}
}