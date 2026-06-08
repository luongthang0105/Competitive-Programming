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
    ll ans = LLONG_MAX;
    for (int i = 2; i <= 10; ++i)
    {
        ll temp_n = n;
        ll cnt = 0;
        while (temp_n > 0)
        {
            cnt += temp_n % i;
            temp_n /= i;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}