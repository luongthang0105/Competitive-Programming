///link: https://oj.vnoi.info/problem/graph_
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

int n, m, num[maxn], low[maxn], visited[maxn];
int bridges, khop[maxn], t;
vector<int> G[maxn];

void dfs(int u, int pre){
    low[u] = num[u] = t++;
    visited[u] = 1;
    int child = 0;
    for(int i : G[u]){
        if(i == pre) continue;
        if(!visited[i])
        {
            dfs(i, u);
            ++child;

            if(num[u] <= low[i] && u != pre) khop[u] = 1;
            if(num[u] < low[i]) ++bridges;

            low[u] = min(low[u], low[i]);
            /// u is updating from its descendants
        }else{///u  meets its ancestor
            low[u] = min(low[u], num[i]);
            ///taking minimum, which is the highest ancestor
            ///comparing w/ num[i], because if we compare it
            /// with low[i], low[u] might get too high and inaccurate
        }
    }
    ///if u is the DFS root => check if it has >1 disconnected subtree
    if(u == pre && child > 1) khop[u] = 1;
}
///clear visualization: https://www.youtube.com/watch?v=sqYozZ2Y_cM
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        G[a].eb(b);
        G[b].eb(a);
    }
    ///do co the co nhieu tplt nen phai chay for
    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            dfs(i,i);
    int ap = 0;
    for(int i = 1; i <= n; ++i)
    {
        ap += khop[i];
    }
    cout << ap << " " << bridges;
    return 0;
}
