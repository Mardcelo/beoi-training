void build(int p, int L, int R, vector<int> const& A) {
    if (L+1 == R) {
        // Single element in the segment
        st[p] = A[L];
    } else {
        // Build both children and then combine
        build(2*p+1, L, (L+R)/2, A);
        build(2*p+2, (L+R)/2, R, A);
        st[p] = st[2*p+1] + st[2*p+2];
    }
}

// Call with:
build(0, 0, n, A);
