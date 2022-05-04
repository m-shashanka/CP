/* Consider func() to be sum for below example */

const int N = 100;

int arr[N], st[4 * N], lazy[4 * N];

//call as build(1,1,arr_size);
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

//call as query(1,1,n,query_start,query_end);
int query(int si, int ss, int se, int qs, int qe) {

    if (lazy[si] != 0) {
        int pending_update = lazy[si];
        lazy[si] = 0;
        st[si] += pending_update * (se - ss + 1);

        if (ss != se) {
            lazy[2 * si] += pending_update;
            lazy[2 * si + 1] += pending_update;
        }
    }

    if (ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return st[si];

    int mid = (ss + se) / 2;

    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

//call as range_update(1,1,n,query_start,query_end,value);
void range_update(int si, int ss, int se, int qs, int qe, int val) {

    if (lazy[si] != 0) {
        int pending_update = lazy[si];
        lazy[si] = 0;
        st[si] += pending_update * (se - ss + 1);

        if (ss != se) {
            lazy[2 * si] += pending_update;
            lazy[2 * si + 1] += pending_update;
        }
    }

    if (ss > qe || se < qs)  return;

    if (ss >= qs && se <= qe) {
        int update = (se - ss + 1) * val;
        st[si] += update;

        if (ss != se) {
            lazy[2 * si] += val;
            lazy[2 * si + 1] += val;
        }
        return;
    }

    int mid = (ss + se) / 2;

    range_update(2 * si, ss, mid, qs, qe, val);
    range_update(2 * si + 1, mid + 1, se, qs, qe, val);

    st[si] = st[2 * si] + st[2 * si + 1];
}

//call as point_update(1,1,n,query_index);
/* update the value in array in O(1) time then pass that index as query_index to this function */
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

