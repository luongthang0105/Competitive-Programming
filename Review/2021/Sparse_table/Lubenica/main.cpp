#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob ""
#define endl "\n"
using namespace std;

typedef int ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 1e5 + 5;

int up[maxn][17], mi[maxn][17], ma[maxn][17];
int n, k, dep[maxn];
vector<pair<int, int>> g[maxn];
int LOG = 16;
void dfs(int u, int par)
{
    for(pii v : g[u])
    {
        int i = v.fi, w = v.se;
        if(i == par) continue;

        dep[i] = dep[u]+1;

        up[i][0] = u;
        mi[i][0] = w;
        ma[i][0] = w;
        for(int j = 1; j <= LOG; ++j)
        {
            up[i][j] = up[up[i][j-1]][j-1];
            mi[i][j] = min(mi[up[i][j-1]][j-1], mi[i][j-1]);
            ma[i][j] = max(ma[up[i][j-1]][j-1], ma[i][j-1]);
        }
        dfs(i, u);
    }
}
void inp()
{
    cin >> n;
    for(int i = 1; i <= n-1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    dep[1] = 0;
    dfs(1,1);
}

int lca(int u, int v)
{
    if(dep[u] > dep[v]) swap(u,v);
    int k = dep[v] - dep[u];
    for(int i = LOG ; i >= 0; --i){
        if(k & (1<<i)) v = up[v][i];
    }
    if(u == v) return u;

    for(int i = LOG ; i >= 0; --i){
        if(up[u][i] != up[v][i])
        {
            v = up[v][i];
            u = up[u][i];
        }
    }
    return up[u][0];
}
int getmin(int u, int v){
    int k = dep[u] - dep[v];
    int ans = INT_MAX;
    for(int i = LOG; i >= 0; --i){
        if(k & (1 << i))
        {
            ans = min(ans, mi[u][i]);
            u = up[u][i];
        }
    }
    return ans;
}
int getmax(int u, int v){
    int k = dep[u] - dep[v];
    int ans = -1;
    for(int i = LOG; i >= 0; --i){
        if(k & (1 << i))
        {
            ans = max(ans, ma[u][i]);
            u = up[u][i];
        }
    }
    return ans;
}
void solve()
{
    cin >> k;
    while(k--){
        int u, v;
        cin >> u >> v;
        int t = lca(u,v);
        int mii = min(getmin(u, t), getmin(v,t));
        int mxx = max(getmax(u, t), getmax(v,t));
        cout << mii << " " << mxx << endl;
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
