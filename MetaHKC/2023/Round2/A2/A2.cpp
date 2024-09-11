// Problem link: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
#include <bits/stdc++.h>
// #pragma comment(linker, "/STACK:268435456");
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "A2" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 3e3 + 5;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0,  0,-1};
vector<vector<char>> board;
vector<vector<bool>> visited;

void dfs(int i, int j, int r, int c, pii &blockingCoord, int &currentCount, int &countNodes) {
    if (i < 0 || i >= r || j < 0 || j >= c) return;
    // if (r == 3000 && c == 3000) {
    //     cout << i << " " << j << " ";
    //     cout << board[i][j] << " " << visited[i][j] << endl;
    // }
    if (visited[i][j] || board[i][j] == 'B') return;
    if (board[i][j] == '.') {
        if (i != blockingCoord.first || j != blockingCoord.second) {
            currentCount += 1;
            blockingCoord = make_pair(i, j);
        }
        return;
    }
    // cout << "hi\n";
    visited[i][j] = true;
    // cout << "Visiting: " << i << " " << j << endl;
    countNodes += 1;
    for (int k = 0; k < 4; ++k) {
        // cout << dy[k] << " " << dx[k] << endl;
        dfs(i + dy[k], j + dx[k], r, c, blockingCoord, currentCount, countNodes);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);
    freopen(prob".txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int r, c;
        cin >> r >> c;
        board = vector(r, vector<char>(c, 0));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> board[i][j];
                // visited[i][j] = false;
            }
        }
        map< pair<int, int>, int> cnt;

        visited = vector(r, vector<bool>(c, false));
        // cout << r << " " << c << endl;
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'W' && !visited[i][j]) {
                    // cout << "-------------------" << endl;
                    pair<int, int> blockingCoord = {-1, -1};
                    int currentCount = 0;
                    int numWNodes = 0;
                    // cout << "Flood from " << i << " " << j << endl;
                    dfs(i, j, r, c, blockingCoord, currentCount, numWNodes);
                    // cout << "count dots: " << " " << currentCount << endl;
                    // cout << "count nodes: " << " " << numWNodes << endl;
                    if (currentCount == 1) {
                        cnt[blockingCoord] += numWNodes;
                        ans = max(ans, cnt[blockingCoord]);
                    } else if (currentCount == 0) {
                        ans = max(ans, numWNodes);
                    }
                }
            }
        }

        cout << "Case #" << k << ": " << ans;
        cout << endl;
    }

}