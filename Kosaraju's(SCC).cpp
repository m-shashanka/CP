// Kosaraju's Algorithm

void dfs(int u, vector<bool> &vis, stack<int> &s) {
	vis[u] = true;
	for (auto v : G[u]) {
		if (!vis[v])
			dfs(v, vis, s);
	}
	s.push(u);
}

stack<int> topoSort(int n) {
	vector<bool> vis(n + 1);
	stack<int> s;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, vis, s);
	return s;
}

void revDfs(int u, vector<bool> &vis, vector<int> transpose[]) {
	cout << u << " ";
	vis[u] = true;
	for (auto v : G[u])
		if (!vis[v])
			revdfs(v, vis, transpose);
}

void kosaraju(int n) {
	//Step 1
	stack<int> s = topoSort(n);

	//Step 2
	vector<int> transpose[n + 1];
	for (int i = 1; i <= n; i++) {
		for (auto v : G[i])
			transpose[v].push_back(i);
	}

	vector<bool> vis(n + 1);

	//Step 3
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		if (!vis[u]) {
			cout << "SCC: ";
			revDfs(u, vis, transpose);
			cout << endl;
		}
	}
}
