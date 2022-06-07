//Tarjan's algorithm

//tin[i] -> time of insertion of this node
//low[i] -> lowest time to reach this node

void dfs(int u, int p, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer) {
	vis[u] = true;
	tin[u] = low[u] = timer++;
	int children = 0;
	bool articulationPoint = false;
	for (auto v : G[u]) {
		if (v == p)
			continue;
		if (vis[v])
			low[u] = min(low[u], tin[v]);
		else {
			dfs(v, u, vis, tin, low, timer);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u])
				articulationPoint = true;
			children++;
		}
	}

	if (articulationPoint && (p != -1 || children > 1))
		cout << u << endl;
}

//dp solution

//dp[i] -> lowest level you can reach from i following only back edges from subtree of i

void dfs(int u, int p, vector<int> &vis, vector<int> &dp, vector<int> &lvl) {
	vis[u] = true;
	if (p != -1)
		lvl[u] = lvl[p] + 1;
	dp[u] = lvl[u];

	bool articulationPoint = false;
	int children = 0;

	for (auto v : G[u]) {
		if (v == p)
			continue;
		if (vis[v])
			dp[u] = min(dp[u], lvl[v]);
		else {
			dfs(v, u, vis, dp, lvl);
			dp[u] = min(dp[u], dp[v]);
			if (dp[v] >= lvl[u])
				articulationPoint = true;
			children++;
		}
	}

	if (articulationPoint && (p != -1 || children > 1))
		cout << u << endl;
}
