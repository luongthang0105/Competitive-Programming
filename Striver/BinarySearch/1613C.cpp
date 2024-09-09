// Problem link: https://codeforces.com/problemset/problem/1613/C
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

bool test(vector<ll> a, ll k, ll h) {
    ll totalDamage = 0LL;
    ll end = a[0] + k - 1;
    a.push_back(LLONG_MAX);
    for (int i = 1; i < a.size(); ++i) {
        if (end < a[i]) {
            totalDamage += end - a[i - 1] + 1;
        } else {
            totalDamage += a[i] - a[i - 1];
        }
        end = a[i] + k - 1;
    }
    // cout << k << " " << totalDamage << endl;
    return totalDamage >= h;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll low = 0, high = 1e18;
        ll ans = high;
        while (low <= high) {
            // cout << low << " " << high << endl;
            ll mid = (low + high) / 2;
            if (test(a, mid, h)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}