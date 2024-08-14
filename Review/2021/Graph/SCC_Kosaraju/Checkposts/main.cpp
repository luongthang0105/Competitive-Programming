///link: https://codeforces.com/problemset/problem/427/C
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
const int maxn = 1e5 + 5;

vector<int> G1[maxn], G2[maxn], luu;
int visited[maxn], n, m;
ll w[maxn], cost = 0;
stack<int> p;
void dfs1(int u)
{
    visited[u] = 1;
    for(int v : G1[u]) if(!visited[v]) dfs1(v);
    p.push(u);
}
void dfs2(int u, unordered_map<ll, int>& m, ll& mi)
{
    visited[u] = 1;
    m[w[u]]++;
    mi = min(mi, w[u]);
    for(int v : G2[u])
        if(!visited[v])
            dfs2(v, m, mi);
}
void kosa()
{
    fill(visited, visited + n + 1, 0);
    while(!p.empty())
    {
        int u = p.top(); p.pop();
        if(!visited[u])
        {
            unordered_map<ll, int> m;
            ll mi = INT_MAX;
            dfs2(u, m, mi);
            cost += mi;
            luu.pb(m[mi]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> w[i];
    cin >> m;
    for(int i = 1; i <= m;++i)
    {
        int a, b;
        cin >> a >> b;
        G1[a].pb(b);
        G2[b].pb(a);
    }
    for(int i = 1; i <= n; ++i)
        if(!visited[i]) dfs1(i);
    kosa();
    cout << cost << " ";
    ll kq = 1;
    for(ll ww : luu)
    {
        kq = (ww*kq) % 1000000007;
    }
    cout << kq;
    return 0;
}
