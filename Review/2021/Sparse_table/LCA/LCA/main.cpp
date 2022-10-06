//link:https://www.spoj.com/problems/LCASQ/
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
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 1e5 + 5;

int up[10000][14], n, k, a;
int depth[10000];
vector<int> g[10000];

void dfs(int u)
{
    int ver;
    for(int i = 0; i < g[u].size(); ++i)
    {
        ver = g[u][i];
        up[ver][0] = u;
        depth[ver] = depth[u] + 1;
        for(int j = 1; j <= 13; ++j)
            up[ver][j] = up[up[ver][j-1]][j-1];
        dfs(ver);
    }
}
void inp()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> k;
        for(int j = 1; j <= k; ++j)
        {
            cin >> a;
            g[i].pb(a);
        }
    }
    depth[0] = 0;
    dfs(0);
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u,v);
    int k = depth[v] - depth[u];
    for(int i = 13; i >= 0; i--)
    {
        if((1<<i)&k) v = up[v][i];
    }
    if(u == v) return u;
    for(int i = 13; i >= 0; --i){
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
void solve()
{
    int q, u, v;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << lca(u,v) << endl;
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
