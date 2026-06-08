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
vector<string> matrix;
vector<vector<int>> dist_matrix;
int w, h;
string ins;
unordered_map<char, pair<int, int>> dir;

void findDist(pii S)
{
    queue<pair<pii, int>> q;
    q.push({S, 0});
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[S.first][S.second] = true;
    while (!q.empty())
    {
        auto [u, cost] = q.front();
        auto &[row, col] = u;
        q.pop();
        for (auto &[dirr, delta] : dir)
        {
            int new_row = row + delta.first;
            int new_col = col + delta.second;
            if (matrix[new_row][new_col] == '#')
                continue;
            if (visited[new_row][new_col])
                continue;
            dist_matrix[new_row][new_col] = cost + 1;
            visited[new_row][new_col] = true;
            q.push({{new_row, new_col}, cost + 1});
        }
    }
}
int main()
{
    dir.insert({'W', {0, -1}});
    dir.insert({'S', {1, 0}});
    dir.insert({'N', {-1, 0}});
    dir.insert({'E', {0, 1}});
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> w >> h;
    matrix.resize(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> matrix[i];
    }
    cin >> ins;

    pair<int, int> S;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (matrix[i][j] == 'S')
            {
                S = make_pair(i, j);
                break;
            }
        }
    }

    queue<tuple<pair<int, int>, int>> q;
    vector<vector<bool>> visited;
    for (int i = 0; i < h; ++i)
    {
        visited.push_back(vector<bool>(w, false));
        dist_matrix.push_back(vector<int>(w, 0));
    }

    findDist(S);

    q.push({S, 0});
    visited[S.first][S.second] = true;
    vector<pair<int, int>> ends;
    while (!q.empty())
    {
        auto top = q.front();
        auto &[u, dist] = top;
        q.pop();
        if (dist == ins.size())
        {
            matrix[u.first][u.second] = '!';
            continue;
        }
        for (auto &[dirr, delta] : dir)
        {
            if (dirr == ins[dist])
                continue;

            int new_row = u.first + delta.first;
            int new_col = u.second + delta.second;
            if (matrix[new_row][new_col] == '#')
                continue;
            if (visited[new_row][new_col])
                continue;
            if (dist + 1 != dist_matrix[new_row][new_col])
            {
                continue;
            }
            visited[new_row][new_col] = true;
            q.push({{new_row, new_col}, dist + 1});
        }
    }
    for (int i = 0; i < h; ++i)
    {
        cout << matrix[i] << endl;
    }
}