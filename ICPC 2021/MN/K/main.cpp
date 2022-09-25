#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob ""
#define endl "\n"
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;
ll n, a[maxn];
ll shelter, ass;
void solve()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> ass >> shelter;

    for(int i = 0; i < n; ++i)
        a[i] = abs(a[i] - shelter);
    sort(a, a + n);
    ll i = 0LL,sum = 0LL, ok = 0LL;
    for(i = 0; i < n; ++i)
    {
        sum += a[i];
        if(sum >= abs(ass-shelter))
        {
            cout << i;
            ok = 1;
            break;
        }
    }
    if (!ok)
        cout << i;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}

