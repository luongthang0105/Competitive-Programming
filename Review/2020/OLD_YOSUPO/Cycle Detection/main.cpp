//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
using namespace std;

typedef int ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 5e5 + 5;

int n, m;
vector<int> g[maxn], id[maxn];
int visit[maxn], z = 0;
void inp()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        id[u].eb(i);
    }
}

vector<pii> path;

void dfs(int u)
{
    visit[u] = 1;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i], idd = id[u][i];
        if(visit[v] == 0)
        {
            path.eb({idd, u});
            dfs(v);
            if(z == 0) path.pop_back();
            else return;
        }
        else if(visit[v] == 1)
        {
            if((int)path.size() < 1) continue;
            z = 1;
            path.eb({idd, u});
            vector<int> ans;
            while(path.back().se != v)
            {
                pii j = path.back();
                path.pop_back();
                ans.eb(j.fi);
            }
            ans.eb(path.back().fi);
            printf("%d\n", ans.size());
            reverse(ans.begin(), ans.end());
            for(int j : ans) printf("%d\n", j);
            return;
        }
    }
    visit[u] = 2;
}
void solve()
{
    for(int i = 0; i < n; ++i)
    {
//        path.clear();
//        fill(visit, visit + n , 0);
        if(visit[i] == 0) dfs(i);
        if(z) return;
    }
    puts("-1");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie(0);//cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
