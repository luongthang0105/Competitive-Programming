#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const ll inf = 1e9 + 7;
int n, m;
ll a[maxn], b[maxn], w;


ll cal(ll a[maxn], int n, ll x)
{
    ll sum = 0, cnt = 0, st = 1;

    for(int i = 1; i <= n + 1; ++i)
    {
        sum += a[i];
        if(i != n + 1 && a[i] > x) return 0;
        if(sum + (i - st) > x)
        {
            sum = a[i];
            ++cnt;
            st = i;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("REPORT.inp","r",stdin);
    freopen("REPORT.out","w",stdout);

    cin >> w >> n >> m;

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    a[n + 1] = inf; b[m + 1] = inf;
    ll l = 1, r = w, ans = inf;

//    for(int i = l; i <= r; ++i)
//    {
//        cout << i << " " << cal(a, n, i) << " " << cal(b, m, w - i) << endl;;
//        //ans = min(ans, max(cal(a, n, i), cal(b, m, w - i)));
//    }
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        ll f1 = cal(a, n, mid), f2 = cal(b, m, w - mid);
        if(f1 == 0) l = mid + 1;
        else if(f2 == 0) r = mid - 1;
        else if(f1 > f2)
        {
            ans = min(ans, f1);
            l = mid + 1;
        }
        else
        {
            ans = min(ans, f2);
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
