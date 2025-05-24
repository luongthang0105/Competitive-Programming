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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows + 2, vector<char>(cols + 2, 'a'));
    int count = 0;
    for (int row = 1; row <= rows; ++row) {
        for (int col = 1; col <= cols; ++col) {
            cin >> grid[row][col];
        }
    }
    vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1 ,-1}, {-1, 1}};
    pair<int, int> location;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (grid[i][j] == '0') {
                bool ok = true;
                for (auto direction : directions) {
                    if (grid[direction.first + i][direction.second + j] != 'O') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    count += 1;
                    location = {i, j};
                }
            }
        }
    }
    if (count == 0) {
        cout << "Oh no!";
    } else if (count == 1) {
        cout << location.first << " " << location.second;
    } else {
        cout << "Oh no! " <<  count << " locations";
    }
}