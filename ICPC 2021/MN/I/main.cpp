///https://oj.vnoi.info/problem/icpc21_mn_i
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;
const int N = 1e6 + 5;
int n, a[maxn];
ll suff[N], pref[N];
ll bit[N];
ll gett(int x)
{
    ll sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= (x & (-x));
    }
    return sum;
}
void update(int x)
{
    while(x <= n)
    {
        bit[x] += 1;
        x += (x & (-x));
    }
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = n; i >= 1; --i)
    {
        pref[a[i]] = gett(a[i]-1);
        update(a[i]);
    }
    for(int i = 1; i <= n; ++i)
        pref[i] += pref[i-1];

    fill(bit, bit+n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        suff[a[i]] = gett(n) - gett(a[i]-1);
        update(a[i]);
    }
    for(int i = n; i >= 1; --i)
        suff[i] += suff[i+1];

    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; ++i)
        ans = min(ans, pref[i-1] + suff[i+1]);

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}

