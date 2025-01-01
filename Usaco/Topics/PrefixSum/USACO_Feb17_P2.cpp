// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "maxcross" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

vector<int> a(maxn);
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(prob".in", "r", stdin);
    // freopen(prob".out", "w", stdout);
    int n, b, k;
    cin >> n >> k >> b;

    for (int i = 0 ; i < b; ++i ) {
        int x; cin >> x;
        a[x] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    int ans = n + 5;
    for (int i = k; i <= n; ++i) {
        ans = min(ans, a[i] - a[i - k]);
    }
    cout << ans;
}