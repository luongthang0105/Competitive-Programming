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

string rotate90(string &base)
{
    vector<string> base_grid;
    for (int i = 0; i < 4; ++i)
    {
        base_grid.push_back(base.substr(i * 4, 4));
    }
    string rotated;
    for (int col = 0; col < 4; ++col)
    {
        for (int row = 3; row >= 0; --row)
        {
            rotated += base_grid[row][col];
        }
        // rotated += temp;
    }
    return rotated;
}
string flip_row(string &base, int row)
{
    string new_grid = base;
    for (int i = row * 4; i < row * 4 + 4; ++i)
    {
        new_grid[i] = (base[i] == '0') ? '1' : '0';
    }
    return new_grid;
}
string flip_col(string &base, int col)
{
    string new_grid = base;
    for (int i = 0; i < 4; ++i)
    {
        new_grid[i * 4 + col] = (base[i * 4 + col] == '0') ? '1' : '0';
    }
    return new_grid;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    // vector<string> a(4);
    // vector<string> b(4);
    string a;
    string b;
    for (int i = 0; i < 4; ++i)
    {
        string x;
        cin >> x;
        a += x;
    }

    for (int i = 0; i < 4; ++i)
    {
        string x;
        cin >> x;
        b += x;
    }
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({a, 0});
    while (!q.empty())
    {
        auto [base, step] = q.front();
        q.pop();

        if (base == b)
        {
            cout << step;
            return 0;
        }
        string rotate = rotate90(base);
        // cout << rotate << endl;
        if (!visited.contains(rotate))
        {
            q.push({rotate, step + 1});
            visited.insert(rotate);
        }
        for (int i = 0; i < 4; ++i)
        {
            string flipped_row = flip_row(base, i);
            if (!visited.contains(flipped_row))
            {
                q.push({flipped_row, step + 1});
                visited.insert(flipped_row);
            }

            string flipped_col = flip_col(base, i);
            if (!visited.contains(flipped_col))
            {
                q.push({flipped_col, step + 1});
                visited.insert(flipped_col);
            }
        }
    }
    cout << -1;
}