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
    int cols, rows;
    cin >> cols >> rows;
    char map[rows + 1][cols + 1];
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            map[i][j] = '.';
        }
    }

    char ch;
    while (cin >> ch)
    {
        if (ch == '#')
            break;
        int r, c;
        while (cin >> c >> r)
        {
            if (r == 0 && c == 0)
                break;
            // cout << r << " " << c << endl;
            map[r][c] = ch;
        }
    }
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}