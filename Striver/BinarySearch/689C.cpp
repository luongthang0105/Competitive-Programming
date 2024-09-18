// Problem link: https://codeforces.com/contest/689/problem/C
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

ll count_ways(ll n) {
    ll cnt = 0LL;
    for (ll i = 2LL; i <= cbrt(n); ++i) {
        cnt += floor(n / (i * i * i));
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    ll m;
    cin >> m;

    ll low = 8, high = 1e18;
    ll ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = count_ways(mid);
        if (cnt == m) {
            ans = mid;
            high = mid - 1;
        } else if (cnt < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
}