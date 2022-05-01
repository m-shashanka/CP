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


//assign base color and then call
for1(i, n) {
	if (color[i] == -1) {
		color[i] = 0;
		dfs(i);
	}
}
