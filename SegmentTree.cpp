class SegTree {
	vl arr, st;
	int n;

	ll query(int si, int ss, int se, int qs, int qe) {
		if (ss > qe || se < qs)
			return SOME_INVALID_DATA;

		if (ss >= qs && se <= qe)
			return st[si];

		int mid = (ss + se) / 2;

		return func(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
	}

	void build(int si, int ss, int se) {
		if (ss == se) {
			st[si] = arr[ss];
			return;
		}

		int mid = (ss + se) / 2;

		build(2 * si, ss, mid);
		build(2 * si + 1, mid + 1, se);

		st[si] = func(st[2 * si], st[2 * si + 1]);
	}

	void point_update(int si, int ss, int se, int qi) {
		if (ss == se) {
			st[si] = arr[qi];
			return;
		}

		int mid = (ss + se) / 2;

		if (qi <= mid)
			point_update(2 * si, ss, mid, qi);
		else
			point_update(2 * si + 1, mid + 1, se, qi);

		st[si] = func(st[2 * si], st[2 * si + 1]);
	}

public:

	SegTree(vl &a) {
		n = sz(a);
		arr = a;
		st.resize(4 * n);
		build(1, 1, n);
	}

	ll query(int qs, int qe) {
		return query(1, 1, n, qs, qe);
	}

	void point_update(int idx, int val) {
		arr[idx] = val;
		point_update(1, 1, n, idx);
	}

};
