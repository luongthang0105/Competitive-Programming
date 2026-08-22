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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> rows(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> rows[i];
    }
    vector<int> emptyRows;
    vector<int> emptyCols;
    for (int i = 0; i < h; ++i)
    {
        if (all_of(rows[i].begin(), rows[i].end(), [](const char &c)
                   { return c == '.'; }))
        {
            emptyRows.push_back(i);
        }
    }

    for (int i = 0; i < w; ++i)
    {
        bool isEmpty = true;
        for (int j = 0; j < h; ++j)
        {
            if (rows[j][i] == '#')
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            emptyCols.push_back(i);
        }
    }

    queue<pair<pii, int>> q;
    set<pii> visited;
    for (auto row : emptyRows)
    {
        for (auto col : emptyCols)
        {
            q.push({{row, col}, 0});

            visited.insert({row, col});
        }
    }

    int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    int count = 0;
    while (!q.empty())
    {
        auto elem = q.front();
        pii u = elem.first;
        int moves = elem.second;
        q.pop();

        count++;
        // cout << u.first << " " << u.second << '\n';
        for (int i = 0; i < 4; ++i)
        {
            int newx = u.first + dirs[i][0];
            int newy = u.second + dirs[i][1];
            if (0 <= newx && newx < h &&
                0 <= newy && newy < w &&
                rows[newx][newy] != '#' &&
                moves + 1 <= k &&
                !visited.contains({newx, newy}))
            {
                visited.insert({newx, newy});
                q.push({{newx, newy}, moves + 1});
            }
        }
    }
    cout << count;
}