// i is the node that is to be updated
// x is the new value
void update(int p, int L, int R, int i, int x) {
    if (L+1 == R) {
        // leaf node
        st[p] = L;
    } else {
        // update one child
        if (i < (L+R)/2) {
            update(2*p+1, L, (L+R)/2, i, x);
        } else {
            update(2*p+2, (L+R)/2, R, i, x);
        }
        // take minimum among them
        int p1 = st[2*p+1], p2 = st[2*p+2];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
}

