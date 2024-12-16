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

const int maxn = 1e2 + 5;
int matrix[maxn][maxn][maxn];
unordered_map<int, int> x_count;
unordered_map<int, int> y_count;
unordered_map<int, int> z_count;
int n , q;

bool x_empty(int y, int z) {
    for (int x = 0; x < n; ++x) {
        if (matrix[x][y][z]) return false;
    }
    return true;
}

bool y_empty(int x, int z) {
    for (int y = 0; y < n; ++y) {
        if (matrix[x][y][z]) return false;
    }
    return true;
}

bool z_empty(int x, int y) {
    for (int z = 0; z < n; ++z) {
        if (matrix[x][y][z]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int k = 0; k < maxn; ++k) {
                matrix[i][j][k] = 1;
            }
        }
    }
    cin >> n >> q;
    int count = 0;
    for (int t = 0; t < q; ++t) {
        int x,y,z;
        cin >> x >> y >> z;
        matrix[x][y][z] = 0;
        count += x_empty(y, z);
        count += y_empty(x, z);
        count += z_empty(x, y);
        cout << count << endl;
    }

}