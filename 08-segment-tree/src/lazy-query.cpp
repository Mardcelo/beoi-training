int query(int p, int L, int R, int i, int j) {
    // This line is new:
    propagate(p, L, R);

    if (i <= L && R <= j) return st[p];
    if (i >= R || L >= j) return 0;

    return query(2*p+1, L, (L+R)/2, i, j)
           + query(2*p+2, (L+R)/2, R, i, j);
}
