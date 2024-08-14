#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

int n;
vector<int> g[maxn];
vector<ll> w[maxn];
void inp()
{
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].eb(v); g[v].eb(u);
        w[u].eb(l); w[v].eb(l);
    }
}

int bfs(int x, int type)
{
    ll d[n + 5], par[n + 5];
    fill(d, d + n + 5, 0);
    fill(par, par + n + 5, -1);
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front(); q.pop();

        for(int i = 0; i < g[u].size(); ++i)
        {
            ll v = g[u][i], l = w[u][i];
            if(v != x && d[v] == 0)
            {
                if(type == 2) par[v] = u;
                d[v] = d[u] + l;
                q.push(v);
            }
        }
    }
    ll ans = 0, ver;
    for(int i = 0; i < n; ++i)
    {
        if(ans < d[i])
        {
            ans = d[i];
            ver = i;
        }
    }

    if(type == 1) return ver;
    int tmp = ver;
    vector<int> path;
    while(par[tmp] != -1)
    {
        path.eb(tmp);
        tmp = par[tmp];
    }
    path.eb(x);
    cout << d[ver] << " " << path.size() << endl;
    for(int i : path) cout << i << " ";
    return 0;
}
void solve()
{
    int tar = bfs(1, 1);
    bfs(tar, 2);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
