//link:https://cses.fi/problemset/task/1135
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
const int maxn = 2e5 + 5;

int up[maxn][18], n, k, q;
int depth[maxn];
vector<int> g[maxn];

void dfs(int u, int pre)
{
    int ver;
    for(int i = 0; i < g[u].size(); ++i)
    {
        ver = g[u][i];
        if(ver == pre) continue;
        up[ver][0] = u;
        depth[ver] = depth[u] + 1;
        for(int j = 1; j <= 17; ++j)
            up[ver][j] = up[up[ver][j-1]][j-1];
        dfs(ver, u);
    }
}
void inp()
{
    cin >> n >> q;
    for(int i = 1; i <= n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[b].pb(a);
        g[a].pb(b);
    }
    depth[1] = 0;
    dfs(1, 1);
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u,v);
    int k = depth[v] - depth[u];
    for(int i = 17; i >= 0; i--)
    {
        if((1<<i)&k) v = up[v][i];
    }
    if(u == v) return u;
    for(int i = 17; i >= 0; --i){
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
    int u, v;
    while(q--)
    {
        cin >> u >> v;
        int t = lca(u,v);
        cout << depth[u] + depth[v] - 2*depth[t] << endl;
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
