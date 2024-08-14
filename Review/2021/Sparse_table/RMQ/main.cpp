//link: https://www.spoj.com/problems/RMQSQ/

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
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 1e5 + 5;

int n, a[maxn];
int m[maxn][17];
void inp()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i], m[i][0] = a[i];
    for(int j = 1; j < 17; ++j)
        for(int i = 0; i+(1<<j)-1 < n; ++i)
            m[i][j] = min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
}

void solve()
{
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int x,y;
        cin >> x >> y;
        int len = y-x+1, j = log2(len);
        cout << min(m[x][j], m[y-(1<<j)+1][j]) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
