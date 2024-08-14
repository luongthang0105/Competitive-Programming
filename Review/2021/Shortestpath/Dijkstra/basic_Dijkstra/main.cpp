///link: https://codeforces.com/problemset/problem/20/C
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
const int maxn = 1e5 + 5;
const ll INF = 1e15;

ll d[maxn], check[maxn], trace[maxn];
vector<pii> E[maxn];
int m,n;
void dijkstra(){
    fill(d, d+n+1, INF);
    fill(trace, trace+n+1, -1);
    priority_queue< pii, vector<pii>, greater<pii> > p;

    d[1] = 0;
    p.push({0, 1});

    while(!p.empty()){
        pii t = p.top();
        p.pop();
        int u = t.se;
        ll du = t.fi;

        if(check[u]) continue;
        check[u] = 1;
        for(pii tt : E[u])
        {
            int v = tt.fi;
            ll w = tt.se;
            if(!check[v] && du + w < d[v])
            {
                d[v] = du + w;
                p.push({d[v], v});
                trace[v] = u;
            }
        }
    }
    if(trace[n] != -1){
        vector<int> print;
        while(trace[n] != 1){
            print.pb(n);
            n = trace[n];
        }
        print.pb(n); print.pb(1);
        reverse(print.begin(), print.end());
        for(int i : print) cout << i << " ";
    }else cout << "-1";
}
void solve()
{
    //while(true)
    {
        cin >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            ll w;
            cin >> a >> b >> w;
            E[a].pb({b, w});
            E[b].pb({a, w});
        }
        dijkstra();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
