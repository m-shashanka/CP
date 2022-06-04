/* Consider func() to be sum for below example */

class LazySegTree {
	vl arr, st, lazy;
	int n;

	void build(int si, int ss, int se) {
		if (ss == se) {
			st[si] = arr[ss];
			return;
		}

		int mid = (ss + se) / 2;

		build(2 * si, ss, mid);
		build(2 * si + 1, mid + 1, se);

		st[si] = st[2 * si] + st[2 * si + 1];
	}

	ll query(int si, int ss, int se, int qs, int qe) {
		if (lazy[si] != 0) {
			ll pending_update = lazy[si];
			lazy[si] = 0;
			st[si] = pending_update * (se - ss + 1);

			if (ss != se) {
				lazy[2 * si] = pending_update;
				lazy[2 * si + 1] = pending_update;
			}
		}

		if (ss > qe || se < qs)
			return 0;

		if (ss >= qs && se <= qe)
			return st[si];

		int mid = (ss + se) / 2;

		return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
	}

	void range_update(int si, int ss, int se, int qs, int qe, ll val) {

		if (lazy[si] != 0) {
			ll pending_update = lazy[si];
			lazy[si] = 0;
			st[si] = pending_update * (se - ss + 1);

			if (ss != se) {
				lazy[2 * si] = pending_update;
				lazy[2 * si + 1] = pending_update;
			}
		}

		if (ss > qe || se < qs)  return;

		if (ss >= qs && se <= qe) {
			ll update = (se - ss + 1) * val;
			st[si] = update;

			if (ss != se) {
				lazy[2 * si] = val;
				lazy[2 * si + 1] = val;
			}
			return;
		}

		int mid = (ss + se) / 2;

		range_update(2 * si, ss, mid, qs, qe, val);
		range_update(2 * si + 1, mid + 1, se, qs, qe, val);

		st[si] = st[2 * si] + st[2 * si + 1];
	}

public:

	LazySegTree(vl &a) {
		n = sz(a) - 1;
		arr = a;
		st.resize(4 * n);
		lazy.resize(4 * n);
		build(1, 1, n);
	}

	ll query(int qs, int qe) {
		return query(1, 1, n, qs, qe);
	}

	void point_update(int idx, ll val) {
		range_update(1, 1, n, idx, idx, val);
	}

	void range_update(int qs, int qe, ll val) {
		range_update(1, 1, n, qs, qe, val);
	}

};
