//Kruskal's

struct Edge {
	int u, v, wt;
	Edge(int x, int y, int w) {
		u = x;
		v = y;
		wt = w;
	}
};

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

int spanningTree(int n, vector<Edge> &e) {
	sort(e.begin(), e.end(),[](const Edge &a, const Edge &b){
		return a.wt < b.wt;
	});

	makeSet(n);

	vector<Edge> mst;
	int cost = 0;

	for (auto x : e) {
		if (findPar(x.u) != findPar(x.v)) {
			cost += x.wt;
			mst.push_back(x);
			Union(x.u, x.v);
		}
	}

	//selected edges
	for (auto x : mst)
		cout << x.u << " " << x.v << " " << x.wt << endl;

	return cost;
}
