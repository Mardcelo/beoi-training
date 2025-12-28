void propagate(int p, int L, int R) {
    if (lazy[p] != 0) {
        st[p] += (R-L)*lazy[p];

        if (L+1 != R) {
            lazy[2*p+1] += lazy[p];
            lazy[2*p+2] += lazy[p];
        }

        lazy[p] = 0;
    }
}
