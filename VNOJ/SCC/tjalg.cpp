// Problem link: https://oj.vnoi.info/problem/tjalg
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
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e4 + 5;
int n, m;

vector<int> graph[maxn];
vector<int> low(maxn, 0), id(maxn, 0);
vector<bool> onStack(maxn, 0), visited(maxn, 0);
stack<int> st;

int global_id = 0;
int scc_count = 0;

void dfs(int u) {
    st.push(u);
    onStack[u] = visited[u] = true;
    low[u] = id[u] = global_id++;

    for (int v : graph[u]) {
        if (!visited[v]) dfs(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }

    if (low[u] == id[u]) {
        while (true) {
            int node = st.top();
            st.pop();

            onStack[node] = false;

            if (node == u) break;
        }
        scc_count++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i);
    }

    cout << scc_count;
}