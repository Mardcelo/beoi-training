#include <bits/stdc++.h>
using namespace std;

vector<int> st;

int query(int p, int L, int R, int i, int j) {
	// Outside
	if (i >= R || L >= j) return 0;
	// Inside
	if (i <= L && R <= j) return st[p];
	// Split
	return query(2*p+1, L, (L+R)/2, i, j) + query(2*p+2, (L+R)/2, R, i, j);
}

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

void update(int p, int L, int R, int i, int x) {
	if (L+1 == R) {
		// Single element in the segment
		st[p] = x;
	} else {
		// Build both children and then combine
		if (i < (L+R)/2) {
			update(2*p+1, L, (L+R)/2, i, x);
		} else {
			update(2*p+2, (L+R)/2, R, i, x);
		}
		st[p] = st[2*p+1] + st[2*p+2];
	}
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;

		vector<int> A(N);
		for (int& x : A) {
			cin >> x;
		}

		st.clear();
		st.resize(4*N);
		build(0, 0, N, A);

		n++;
		if (n > 1) {
			cout << "\n";
		}
		cout << "Case " << n << ":\n";

		char action;
		while (true) {
			cin >> action;
			if (action == 'S') {
				int x, r;
				cin >> x >> r;
				update(0, 0, N, x-1, r);
			} else if (action == 'M') {
				int x, y;
				cin >> x >> y;
				int res = query(0, 0, N, x-1, y);
				cout << res << "\n";
			} else {
				cin >> action >> action;
				break;
			}
		}
	}
	return 0;
}

