//prefer bfs over dfs as it checks for cycle also

vi topo(int n) {
	vi indegree(n + 1);
	for1(u, n) {
		for (auto v : G[u])
			indegree[v]++;
	}

	queue<int> q;
	for1(i, n) {
		if (indegree[i] == 0)
			q.push(i);
	}

	vi topo;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo.pb(u);
		for (auto v : G[u]) {
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}

	if (sz(topo) != n) {
		//cycle present
		return {};
	}

	return topo;
}