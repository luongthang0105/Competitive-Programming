// Source: https://usaco.guide/general/io
// Problem statement: https://usaco.org/index.php?page=viewproblem2&cpid=595
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main() {
	// freopen("hps.in", "r", stdin);
	// freopen("hps.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> prefSum(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char x; cin >> x;
			if (x == '.') {
				prefSum[i][j] = 0;
			} else {
				prefSum[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			prefSum[i][j] += prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
			// cout << prefSum[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= q; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 1 1 2 2
		// pref[2][2] = 2
		// pref[0][2] = 0
		// pref[]
		cout << (prefSum[x2][y2] - prefSum[x1 - 1][y2] - prefSum[x2][y1 - 1] + prefSum[x1 - 1][y1 - 1]) << endl;
	}
}
