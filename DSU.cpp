//Union by Rank and Path Compression

int parent[N], rank[N];

void makeSet(n) {
	for1(i, n) {
		parent[i] = i;
		rank[i] = 0;
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

	if (rank[u] < rank[v])
		parent[u] = v;
	else if (rank[v] < rank[u])
		parent[v] = u;
	else {
		parent[v] = u;
		rank[u]++;
	}
}
