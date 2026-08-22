// Problem link:
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

const int maxn = 1e5 + 5;

int dfs(int u, int par, vector<int> &visited, const vector<vector<int>> &graph, unordered_map<int, int> &trace, vector<int> &res, int ord)
{
    trace[u] = ord;
    visited[u] = true;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (trace.contains(v))
        {
            int numItems = (ord - trace[v] + 1);
            if (numItems & 1)
            {
                // trace_to_res(trace, res, trace[v], ord);
                res.push_back(u);
                return numItems - 1;
            }
        }
        else if (!visited[v])
        {
            int numItemsLeft = dfs(v, u, visited, graph, trace, res, ord + 1);
            if (numItemsLeft > 0)
            {
                res.push_back(u);
                return --numItemsLeft;
            }
            else if (numItemsLeft == 0)
            {
                return 0;
            }
        }
    }

    trace.erase(u);

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        unordered_map<int, int> trace;
        vector<int> res, visited(n + 1, false);
        int hasRes = false;
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i])
                continue;
            if (dfs(i, -1, visited, graph, trace, res, 0) == 0)
            {
                cout << res.size() << '\n';
                for (const auto u : res)
                {
                    cout << u << " ";
                }
                hasRes = true;
                break;
            }
        }
        if (!hasRes)
            cout << -1;
        cout << '\n';
    }
}