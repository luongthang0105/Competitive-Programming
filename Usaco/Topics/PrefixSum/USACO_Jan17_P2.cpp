// Source: https://usaco.guide/general/io
// Problem statement: https://usaco.org/index.php?page=viewproblem2&cpid=595
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> fwdHoof(maxn);
vector<int> fwdPaper(maxn);
vector<int> fwdScissor(maxn);

vector<int> backHoof(maxn);
vector<int> backPaper(maxn);
vector<int> backScissor(maxn);

vector<char> a;

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char x; cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == 'H') {
            fwdHoof[i] = 1;
        } else if (a[i] == 'P') {
            fwdPaper[i] = 1;
        } else {
            fwdScissor[i] = 1;
        }

        if (i > 0) {
            fwdHoof[i] += fwdHoof[i - 1];
            fwdPaper[i] += fwdPaper[i - 1];
            fwdScissor[i] += fwdScissor[i - 1];
        }
	} 

	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 'H') {
            backHoof[i] = 1;
        } else if (a[i] == 'P') {
            backPaper[i] = 1;
        } else {
            backScissor[i] = 1;
        }

        if (i < n - 1) {
            backHoof[i] += backHoof[i + 1];
            backPaper[i] += backPaper[i + 1];
            backScissor[i] += backScissor[i + 1];
        }
	} 

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans = max(ans, max3(backHoof[i], backPaper[i], backScissor[i]));
        } else {
            int leftMax = max3(backHoof[i], backPaper[i], backScissor[i]);
            int rightMax = max3(fwdHoof[i - 1], fwdPaper[i - 1], fwdScissor[i - 1]);
            ans = max(ans, leftMax + rightMax);
        }
        // cout << i << " " << ans << endl; 
    }
    
	cout << ans;
}
