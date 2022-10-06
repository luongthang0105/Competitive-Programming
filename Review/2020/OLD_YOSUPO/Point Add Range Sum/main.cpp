//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int maxn = 5e5 + 5;

int n, q;
ll a[maxn], st[4 * maxn];
void inp()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];

}

void build(int k, int l, int r)
{
    if(l == r)
    {
        st[k] = a[l]; return;
    }
    int mid = (l + r) >> 1;
    build(k*2, l, mid); build(k*2+1, mid + 1, r);
    st[k] = (st[k*2] + st[k*2+1]);
}

void update(int k, int l, int r, int i)
{
    if(l == r)
    {
        st[k] = a[l]; return;
    }
    int mid = (l + r) >> 1;
    if(l <= i && i <= mid) update(k*2, l, mid, i);
    else update(k*2+1, mid + 1, r, i);
    st[k] = (st[k*2] + st[k*2+1]);
}
ll tv(int k, int l, int r, int i, int j)
{
    if(j < l || r < i) return 0;

    if(i <= l && r <= j)
        return st[k];

    int mid = (l + r) >> 1;
    return (tv(k*2, l, mid, i, j) + tv(k*2+1, mid + 1, r, i, j));
}
void solve()
{
    build(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        int l, t; ll r;
        cin >> t >> l >> r;
        if(t == 0)
        {
            a[l+1] += r;
            update(1, 1, n, l+1);
        }
        else
        cout << tv(1, 1, n, l + 1, r) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
