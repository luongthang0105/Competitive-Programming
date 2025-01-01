// Problem link: https://codeforces.com/contest/1826/problem/D
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        for (int i = 0; i < n; ++i) {
            leftMax[i] = b[i] + i;
            if (i > 0) {
                leftMax[i] = max(leftMax[i], leftMax[i - 1]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            rightMax[i] = b[i] - i;
            if (i < n - 1) {
                rightMax[i] = max(rightMax[i], rightMax[i + 1]);
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans = max(ans, leftMax[i-1] + b[i] + rightMax[i+1]);
        }
        cout << ans << endl;
    }
}