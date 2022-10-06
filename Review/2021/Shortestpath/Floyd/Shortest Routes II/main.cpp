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
const int maxn = 250;
const ll INF = 1e8;
ll d[maxn][maxn], trace[maxn][maxn];
int n, m ,q;

void init_trace() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            trace[u][v] = u;
        }
    }
}
void solve()
{
    while(true)
    {
        cin >> n >> m >> q;
        if(n == 0) break;
        for(int i = 1; i <= maxn-5; ++i)
            for(int j = 1;j <= maxn-5; ++j)
                d[i][j] = (i!=j)?INF:0;
        init_trace();
        for(int i = 1; i <= m; ++i)
        {
            int x, y; ll w;
            cin >> x >> y >> w;
            ++x, ++y;
            d[x][y] = min(w, d[x][y]);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                for(int z = 1; z <= n; ++z)
                    if(d[j][i] != INF && d[i][z]!= INF)
    /// if there are some weights < 0, must have the above IF cond!
    /// because: IF d[j][z] == INF & (d[j][i] < 0 and d[i][z] == INF) (and viceversa)
    /// => d[j][z] will be updated (it shouldn't be!)
                    if(d[j][z] > d[j][i] + d[i][z])
                        d[j][z] = d[j][i] + d[i][z];
                        //trace[j][z] = trace[i][z];
        }
        ///check neg cycle
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                for(int z = 1; z <= n; ++z)
                    if(d[j][i] != INF && d[i][z]!= INF)
                    if(d[i][i] < 0) ///this means vertex i is in a neg cycle
                    /// => any path contains i will meet i, and run thru a neg cyc
                    /// => the path's weight eventually becomes -inf
                        d[j][z] = -INF;
        }
        for(int i = 1; i <= q; ++i)
        {
            int a,b;
            cin >> a >> b;
            ++a; ++b;
            //if(t == 0)
            {
                if(d[a][b] == -INF) cout << "-Infinity";
                else if(d[a][b] != INF) cout << d[a][b];
                else cout << "Impossible";
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
