// Problem link: https://atcoder.jp/contests/abc125/tasks/abc125_c
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> fwdGCD(n);
    vector<int> bwdGCD(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            fwdGCD[i] = a[i];
        } else {
            fwdGCD[i] = __gcd(a[i], fwdGCD[i - 1]);
        }
        // cout << fwdGCD[i] << " ";
    }
    // cout << endl;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            bwdGCD[i] = a[i];
        } else {
            bwdGCD[i] = __gcd(a[i], bwdGCD[i + 1]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // cout << bwdGCD[i] << " " ;
        if (i == 0) {
            ans = max(ans, bwdGCD[i + 1]);
        } else if (i == n - 1) {
            ans = max(ans, fwdGCD[i - 1]);
        } else {
            ans = max(ans, __gcd(fwdGCD[i - 1], bwdGCD[i + 1]));
        }
    }
    cout << ans;
}