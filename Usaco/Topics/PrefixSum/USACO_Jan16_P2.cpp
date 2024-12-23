// Source: https://usaco.guide/general/io
// Problem statement: https://usaco.org/index.php?page=viewproblem2&cpid=595
#include <bits/stdc++.h>
using namespace std;

vector<long long> prefSum(50005);
long long get_sum(int start, int end) {
	if (start == 0) return prefSum[end];
	return prefSum[end] - prefSum[start - 1];
}
int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long x; cin >> x;
		prefSum[i] = x;
		if (i != 0) {
			prefSum[i] += prefSum[i-1];
		}
		// cout << prefSum[i] << " " << x << endl;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + ans; j < n; ++j) {
			long long sum = get_sum(i, j);
			if (sum % 7 == 0) {
				// cout << i << " " << j << endl;
				ans = max(ans, j - i + 1);
			}	
		}
	}
	cout << ans;
}
