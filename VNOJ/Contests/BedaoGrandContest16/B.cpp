#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pii;
typedef vector<ll> vll;

const int maxn = 2e5 + 5;

int m, n;
int cur_id = 0;
vector<pii> graph[maxn], dag[maxn];
vector<int> low(maxn, 0), id(maxn, 0);
vector<ll> scc_sum(maxn, 0), dp(maxn, 0);
stack<int> st;
vector<bool> onStack(maxn, 0), visited(maxn, 0);
vector<int> topo;
unordered_map<int, unordered_map<int, ll>> sccEdge;

void dfs(int u) {
    onStack[u] = visited[u] = true;
    low[u] = id[u] = cur_id++;
    st.push(u);

    for (pii p : graph[u]) {
        int v = p.first;
        if (!visited[v]) dfs(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }

    // If low and id is the same, this signal a cycle.
    // Remember to pop nodes from stack and reset onStack values
    if (low[u] == id[u]) {
        while (true) {
            int nodeInCycle = st.top();
            
            st.pop();
            onStack[nodeInCycle] = false;

            // Now consider nodes that are not in this SCC, we need to create
            // edges from this scc to other scc
            for (pii p : graph[nodeInCycle]) {
                int adj = p.first;
                if (low[adj] != low[nodeInCycle]) {
                    sccEdge[low[nodeInCycle]][low[adj]] = max(sccEdge[low[nodeInCycle]][low[adj]], p.second);
                }
            }
            if (nodeInCycle == u) break;
        }
    }
}

ll exploitEdge(ll w) {
    ll sum = 0;
    while (w > 0) {
        sum += w;
        w /= 2;
    }
    return sum;
}

void topo_dfs(int u) {
    visited[u] = true;
    // cout << "On scc " << u << " \n";
    for (auto it : sccEdge[u]) {
        int v = it.first;
        // cout << v << endl;
        if (!visited[v]) topo_dfs(v);
    }
    topo.pb(u);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].pb(make_pair(v, w));
    }

    // Find SCC and assign SCC id
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }   

    for (int u = 1; u <= n; ++u) {
        // cout << "vertex: " << u << ", scc: " << low[u] << endl;
        for (pii p : graph[u]) {
            int v = p.first;
            ll w = p.second;

            if (low[u] == low[v]) {
                // if low is the same, these two vertices 
                // are in the same SCC
                scc_sum[low[u]] += exploitEdge(w);
                // cout << low[u] << " " << scc_sum[low[u]] << endl;
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     if (scc_sum[i] == 0) continue;
    //     cout << "scc: " << i << ", " << scc_sum[i] << endl;
    // }
   
    // now we need a dfs to find topo sort
    fill(visited.begin(), visited.end(), 0);
    
    topo_dfs(0);

    reverse(topo.begin(), topo.end());

    dp[0] = scc_sum[0];
    
    for (int u : topo) {
        // cout << "Process u: " << u << endl;
        for (auto it : sccEdge[u]) {
            int v = it.first;
            ll w = it.second;
            // cout << u << "-->" << v << " : " << w << endl;
            dp[v] = max(dp[v], dp[u] + w + scc_sum[v]);
            // cout << dp[v] << endl;
        }
    }


    cout << *max_element(dp.begin(), dp.end());
}