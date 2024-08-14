//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "triangles"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e2 + 5;

struct vt{
    int x, y;
};
vt a[maxn];
int n;
void inp()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
}

int dt(vt g, vt h, vt t)
{
    int s1 = (h.x - g.x) * (h.y + g.y);
    int s2 = (t.x - h.x) * (t.y + h.y);
    int s3 = (g.x - t.x) * (g.y + t.y);
    return s1 + s2 - s3;
}
void solve()
{
    int ans = 0;
    for(int i = 1; i <= n - 2; ++i)
    {
        for(int j = i + 1; j <= n - 1; ++j)
        {
            for(int k = j + 1; k <= n; ++k)
            {
                ans = max(ans, dt(a[i], a[j], a[k]));
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
