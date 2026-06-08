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
int n, m;
double t;
vector<vector<int>> graph;
unordered_map<int, unordered_map<int, double>> time_taken, speed_up_factor;
const double EPS = 1e-9;
double get_new_dist(int u, int v, double best_dist_to_u)
{
    double old_time = time_taken[u][v];
    double speed_up = speed_up_factor[u][v];
    if (best_dist_to_u < t)
    {
        if (best_dist_to_u + old_time - t >= EPS)
        {
            double time_before_speed_up = t;
            double time_after_speed_up = best_dist_to_u + old_time - t;
            return time_before_speed_up + time_after_speed_up / speed_up;
        }
        else
        {
            return best_dist_to_u + old_time;
        }
    }
    else
    {
        return best_dist_to_u + old_time / speed_up;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m >> t;
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        double bf, af;
        double weight;
        cin >> x >> y >> weight >> bf >> af;
        graph[x].push_back(y);
        graph[y].push_back(x);

        time_taken[x][y] = time_taken[y][x] = weight / bf;

        speed_up_factor[x][y] = speed_up_factor[y][x] = af / bf;
    }
    using pr = pair<double, int>;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, 1});
    vector<double> dist(n + 1, 1e15);
    dist[1] = 0;
    while (!pq.empty())
    {
        auto [best_dist_to_u, u] = pq.top();
        pq.pop();

        if (dist[u] != best_dist_to_u)
            continue;

        if (u == n)
        {
            cout << fixed << setprecision(10) << dist[u];
            return 0;
        }

        for (int v : graph[u])
        {
            double new_dist = get_new_dist(u, v, best_dist_to_u);
            if (dist[v] - new_dist >= EPS)
            {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
    return 0;
}
