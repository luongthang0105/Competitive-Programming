///link: https://open.kattis.com/problems/shortestpath3
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
const int maxm = 5e3 + 5;
const int maxn = 1e3 + 5;

struct Edge{
    ll u, v, w;
};
int n, m, q, s;
Edge E[maxm];
ll d[maxn];

void bell_ford(){
    fill(d, d + maxn, INT_MAX);
    d[s] = 0;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int u = E[j].u, v = E[j].v, w = E[j].w;
            if(d[u] != INT_MAX && d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }

    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= m; ++j)
        {
            int u = E[j].u, v = E[j].v, w = E[j].w;
            if(d[u] != INT_MAX && d[v] > d[u] + w){
                d[v] = -INT_MAX;
            }
        }
    }
}
void solve()
{
    int ok = 1;
    while(ok){
        cin >> n >> m >> q >> s;
        for(int i = 1; i <= m; ++i)
        {
            cin >> E[i].u >> E[i].v >> E[i].w;
        }
        if(n == 0) return;
        bell_ford();

        for(int i = 1; i <= q; ++i){
            int x;
            cin >> x;
            if(d[x] == -INT_MAX) cout << "-Infinity";
            else if(d[x] == INT_MAX) cout << "Impossible";
            else cout << d[x];
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
