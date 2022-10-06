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

vector<int> g[maxn];
int n, m, num[maxn], low[maxn], khop[maxn];
int cnt = 0, cau = 0, k = 0;
void inp()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
}

void dfs(int u, int p)
{
    low[u] = num[u] = ++cnt;
    int child = 0;
    for(int v : g[u])
    {
        if(num[v] == 0)
        {
            ++child;
            dfs(v, u);

            if(low[v] >= num[u])
                khop[u] = (u == p) ? (child > 1) : 1;

            if(low[v] > num[u]) ++cau;

            low[u] = min(low[u], low[v]);
        }else if(v != p)
            low[u] = min(low[u], num[v]);
    }
}

void solve()
{
    for(int i = 1; i <= n; ++i) if(num[i] == 0) dfs(i, i);
    for(int i = 1; i <= n; ++i) if(khop[i]) ++k;
    cout << k << " " << cau;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
