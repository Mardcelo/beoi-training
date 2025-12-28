// p is array index of current node, 
// [L,R[ is current segment, 
// [i,j[ is search interval
// returns: position of the minimum element
int query(int p, int L, int R, int i, int j) {
    // inside  query range
    if (i <= L && R <= j) return st[p];
    // outside query range
    if (i >= R || L >= j) return 0;
    // sum the left and right subintervals
    return query(2*p+1, L, (L+R)/2, i, j)
           + query(2*p+2, (L+R)/2, R, i, j);
}

// Starting a query:
query(0, 0, n, i, j);
// CAREFUL with i, j: 0-indexed, inclusive-exclusive!
