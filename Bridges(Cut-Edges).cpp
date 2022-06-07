//Tarjan's algorithm

//tin[i] -> time of insertion of this node
//low[i] -> lowest time to reach this node

void dfs(int u, int p, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer) {
	vis[u] = true;
	tin[u] = low[u] = timer++;
	
	for (auto v : G[u]) {
		if (v == p)
			continue;
		if (vis[v])
			low[u] = min(low[u], tin[v]);
		else {
			dfs(v, u, vis, tin, low, timer);
			if (low[v] > tin[u])
				cout << "Bridge between " << u << " and " << v << endl;
			low[u] = min(low[u], low[v]);
		}
	}
}

//dp solution

//dp[i] -> lowest level you can reach from i following only back edges from subtree of i

void dfs(int u, int p, vector<bool> &vis, vector<int> &dp, vector<int> &lvl) {
	vis[u] = true;
	if (p != -1)
		lvl[u] = lvl[p] + 1;
	dp[u] = lvl[u];
	
	for (auto v : G[u]) {
		if (v == p)
			continue;
		if (vis[v])
			dp[u] = min(dp[u], lvl[v]);
		else {
			dfs(v, u, vis, dp, lvl);
			dp[u] = min(dp[u], dp[v]);
			if (dp[v] > lvl[u])
				cout << "Bridge between " << u << " and " << v << endl;
		}
	}
}
