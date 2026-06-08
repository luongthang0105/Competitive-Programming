// Problem link:
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll ans = LLONG_MAX;
        for (int x = -m; x < m; ++x)
        {
            ll totalOps = 0;
            for (int i = 0; i < n; ++i)
            {
                double newNum = (a[i] - x);
                totalOps += min(abs(newNum - ceil(newNum / m) * m), abs(newNum - floor(newNum / m) * m));
            }
            ans = min(ans, totalOps);
            cout << "x: " << x << "; totalOps: " << totalOps << endl;
        }
        cout << ans << endl;
    }
}