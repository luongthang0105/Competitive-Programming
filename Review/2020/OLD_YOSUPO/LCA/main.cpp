//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int maxn = 5e5 + 5;

int n, q, bo[maxn][21], h[maxn];
vector<int> g[maxn];

void inp()
{
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int u; cin >> u;
        g[u].eb(i); g[i].eb(u);
    }

}

void dfs(int u)
{
    for(int v : g[u])
    {
        if(v != bo[u][0])
        {
            h[v] = h[u] + 1;
            bo[v][0] = u;
            for(int i = 1; i <= 20; ++i)
                bo[v][i] = bo[bo[v][i-1]][i-1];
            dfs(v);
        }
    }
}

int lca(int u, int v)
{
    if(h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for(int i = 0; i <= 20; ++i)
        if((delta >> i) & 1) u = bo[u][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; --i)
    {
        if(bo[u][i] != bo[v][i])
        {
            u = bo[u][i];
            v = bo[v][i];
        }
    }
    return bo[u][0];
}
void solve()
{
    h[0] = 1;
    dfs(0);
    for(int i = 1; i <= q; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
