#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob ""
#define endl "\n"
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 5e3 + 5;

int n, m;
int cols[maxn][maxn], rows[maxn][maxn];
bool a[maxn][maxn];

bool checked(int mid, int row, int col)
{
    int left_row = col - mid, right_row = col + mid;
    int sum_row = rows[row][right_row];
    if(left_row - 1 >= 0) sum_row -= rows[row][left_row-1];
    if(sum_row != 2*mid+1){
        return false;
    }
    /// pref sum on col
    int high_col = row - mid, low_col = row + mid;
    int sum_col = cols[low_col][col];
    if(high_col - 1 >= 0) sum_col -= cols[high_col-1][col];
    if(sum_col != 2*mid+1){
        return false;
    }
    return true;
}
void solve()
{
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
    {
        string s; cin >> s;
        for(int j = 0; j < n; ++j)
            a[i][j] = s[j] - '0';
    }
    for(int j = 0; j < n; ++j)
        for(int i = 0; i < m; ++i)
        {
            if(i == 0) cols[i][j] = a[i][j];
            else if(a[i][j]) cols[i][j] = cols[i-1][j] + 1;
            else cols[i][j] = cols[i-1][j];
        }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(j == 0) rows[i][j] = a[i][j];
            else if(a[i][j]) rows[i][j] = rows[i][j-1] + 1;
            else rows[i][j] = rows[i][j-1];

    int k = -1, row_id, col_id;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i][j])
            {
                int mid = k+1, ok = 0;
                while(1){
                    if(checked(mid, i, j))
                    {
                        k = mid;
                        mid++;
                        ok = 1;
                    }
                    else break;
                }
                if(ok){
                    row_id = i;
                    col_id = j;
                }
            }
    if(k != -1)
    {
        cout << k*4+1 << endl;
        cout << row_id + 1 << " " << col_id + 1;
    }
    else cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}

