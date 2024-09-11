// Problem link: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "A1" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0,  0,-1};

bool dfs(int i, int j, int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited) {
    if (i < 0 || i >= r || j < 0 || j >= c) return false;
    if (visited[i][j]) return false;
    if (board[i][j] == '.') return true;
    else if (board[i][j] == 'B') return false;

    // cout << "Visiting: " << i << " " << j << endl;
    visited[i][j] = true;

    bool ans = false;
    for (int k = 0; k < 4; ++k) {
        ans |= dfs(i + dy[k], j + dx[k], r, c, board, visited);
    }
    return ans;
}
bool check(vector<vector<char>>& board, int r, int c) {
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'W' && !visited[i][j]) {
                // cout << "-------------------" << endl;
                bool escaped = dfs(i, j, r, c, board, visited);
                if (!escaped) return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> board(r, vector<char>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> board[i][j];
            }
        }
        
        bool found = false;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] != '.') continue;
                board[i][j] = 'B';
                // cout << i << " " << j << endl;
                if (check(board, r, c)) {
                    found = true;
                    break;
                }
                board[i][j] = '.';
            }
            if (found) break;
        }

        cout << "Case #" << k << ": ";
        if (!found) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << endl;
    }

}