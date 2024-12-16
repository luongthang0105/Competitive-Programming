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
map<pair<int, int>, int> xy_count;
map<pair<int, int>, int> yz_count;
map<pair<int, int>, int> xz_count;
int n , q;

bool xy_empty(int x, int y) {
    if (xy_count.find({x, y}) == xy_count.end()) {
        xy_count[{x, y}] = n - 1;
    } else {
        xy_count[{x, y}] -= 1;
    }
    return xy_count[{x,y}] == 0;
}
bool yz_empty(int y, int z) {
    if (yz_count.find({y, z}) == yz_count.end()) {
        yz_count[{y, z}] = n - 1;
    } else {
        yz_count[{y, z}] -= 1;
    }
    return yz_count[{y, z}] == 0;
}
bool xz_empty(int x, int z) {
    if (xz_count.find({x, z}) == xz_count.end()) {
        xz_count[{x, z}] = n - 1;
    } else {
        xz_count[{x, z}] -= 1;
    }
    return xz_count[{x, z}] == 0;
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
        count += xy_empty(x, y);
        count += yz_empty(y, z);
        count += xz_empty(x, z);
        cout << count << endl;
    }

}