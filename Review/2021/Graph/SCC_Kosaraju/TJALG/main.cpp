///link: https://oj.vnoi.info/problem/tjalg
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
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 1e4 + 5;

vector<int> G1[maxn], G2[maxn];
int visited[maxn], n, m;
int tpltm = 0;
stack<int> p;

void dfs1(int u, bool ok)
{
    visited[u] = 1;
    if(ok)
    {
        for(int v : G1[u])
            if(!visited[v]) dfs1(v, ok);
        p.push(u);
    }
    else{
        for(int v : G2[u])
            if(!visited[v]) dfs1(v, ok);
    }

}
void kosa()
{
    fill(visited, visited+n+1, 0);
    while(!p.empty())
    {
        int u = p.top();
        p.pop();
        if(!visited[u])
        {
            ++tpltm;
            dfs1(u, 0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        G1[a].pb(b);
        G2[b].pb(a);
    }

    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            dfs1(i, 1);
    kosa();
    cout << tpltm;
    return 0;
}
