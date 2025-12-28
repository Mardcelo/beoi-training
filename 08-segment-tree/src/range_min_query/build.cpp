void build(int p, int L, int R) {
    if (L+1 == R) {
        // leaf node
        st[p] = L;
    } else {
        // build children
        build(2*p+1, L, (L+R)/2);
        build(2*p+2, (L+R)/2, R);
        // take minimum among them
        int p1 = st[2*p+1], p2 = st[2*p+2];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
}

