//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb push_back
#define pb push_back
#define fi first
#define se second
#define prob "DIJKSTRA"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, int> pii;
typedef vector<ll> vii;

const int maxn = 5e5 + 5;

int n, m, s, t, par[maxn];
vector<pii> g[maxn];
ll d[maxn];
void inp()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb({v, w});
    }
}

void dij()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1}); /// duong di bat dau tu 1
    fill(d, d + n, LLONG_MAX);
    d[s] = 0;
    while(q.size())
    {
        ll tt = q.top().fi;
        ll u = q.top().se;
        q.pop();
        if(tt != d[u]) continue;
        for(pii v : g[u])
        {
            if(d[v.fi] > d[u] + v.se)
            {
                d[v.fi] = d[u] + v.se;
                q.push({d[v.fi], v.fi});
            }
        }
    }
    cout << d[n];
}
void solve()
{
    fill(par, par + n, -1);
    dij();
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
