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
    ll n;
    cin >> n;
    ll l = 1, h = ll(2e6);
    ll best = -1;
    auto sum = [](ll &level)
    {
        return (level + 1) * level / 2;
    };

    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (sum(mid) <= n)
        {
            best = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << best;
}