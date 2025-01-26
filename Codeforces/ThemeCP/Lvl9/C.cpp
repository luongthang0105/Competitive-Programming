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

int countBranches(int u, vector<vector<int>>& g, vector<int>& visited) {
    int count = 0;
    int hasOutgoingVertice = false;
    visited[u] = true;
    for (int v : g[u]) {
        if (visited[v]) {
            continue;
        }
        count += countBranches(v, g, visited);
        count += 1;
        hasOutgoingVertice = true;
    }
    return count - hasOutgoingVertice;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> degree(n + 1, 0);
        for (int i = 0; i < n - 1; ++i)  {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // just need to start from somewhere with deg == 1
        vector<int> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 1) {
                int count = countBranches(i, g, visited);
                if (count == 0) count = 1;
                cout << count << endl; 
                break;
            }
        }
    }
}