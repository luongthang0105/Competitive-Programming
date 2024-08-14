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

ll bit[maxn], n, k;

void add(int idx, ll d)
{
    while(idx <= n){
        bit[idx] += d;
        idx += idx & (-idx); ///update idx to reach a new interval containing the "initial" idx
    }
}
void inp()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        ll x; cin >> x;
        add(i, x);
    }
}

ll sum(int idx){
    ll kq = 0;
    while(idx > 0)
    {
        kq += bit[idx];
        idx -= idx & (-idx); ///flip the right-most bit 1 (0101 -> 0100)
    }
    return kq;
}
void solve()
{
    while(k--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            add(x, y);
        }
        else{
            cout << sum(y) - sum(x-1) << endl;
        }
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




