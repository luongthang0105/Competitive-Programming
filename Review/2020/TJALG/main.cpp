//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

vector<int> g[maxn], f[maxn];
int n, m, visit[maxn];
stack<int> s;
void inp()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].eb(v); f[v].eb(u);
    }
}

void dfs1(int u)
{
    visit[u] = 1;
    for(int v : g[u]) if(!visit[v]) dfs1(v);
    s.push(u);
}

void dfs2(int u)
{
    visit[u] = 1;
    for(int v : f[u]) if(!visit[v]) dfs2(v);
}
void solve()
{
    for(int i = 1; i <= n; ++i)
        if(!visit[i]) dfs1(i);
    fill(visit, visit + n + 1, 0);
    int scc = 0;
    while(!s.empty())
    {
        int v = s.top(); s.pop();
        if(!visit[v])
        {
            ++scc; dfs2(v);
        }
    }
    cout << scc;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
