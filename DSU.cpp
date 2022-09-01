//Union by Rank and Path Compression

int parent[N], Rank[N];

void makeSet(int n) {
	for1(i, n) {
		parent[i] = i;
		Rank[i] = 0;
	}
}

int findPar(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findPar(parent[node]);
}

void Union(int u, int v) {
	u = findPar(u);
	v = findPar(v);

	if (Rank[u] < Rank[v])
		parent[u] = v;
	else if (Rank[v] < Rank[u])
		parent[v] = u;
	else {
		parent[v] = u;
		Rank[u]++;
	}
}
