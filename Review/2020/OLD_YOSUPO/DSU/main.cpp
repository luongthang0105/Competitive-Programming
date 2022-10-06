#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const int maxn = 2e5 + 5;

int n, q;
int par[maxn];
void inp()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) par[i] = i;
}

int findd(int x)
{
    if(par[x] == x) return x;
    return par[x] = findd(par[x]);
}
void solve()
{
    for(int i = 1; i <= q; ++i)
    {
        int u, v, t;
        cin >> t >> u >> v;
        int x = findd(u), y = findd(v);
        if(t == 0)
        {
            if(x != y)
                par[x] = y;
        }
        else
        {
            cout << (x == y) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
