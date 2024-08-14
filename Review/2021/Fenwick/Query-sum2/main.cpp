/// brief summary:
/// initially we have array A[i], from 2nd line of input
/// create array diff[j] with diff[1] = a[1], and diff[i] = a[i] - a[i-1]
/// say, we have to increase the value of A[i] -> A[j]
/// Example:
///        1  2 3 4  5 6  7 8
/// A    = 5  1 2 8  5 9  3 5
/// Diff = 5 -4 1 6 -3 4 -6 2
///               *  * *  *
/// New A= 5  1 2 12 9 13 7 5
//=> Diff= 5 -4 1 10 -3 4 -6 -2
/// So, only at index 4 and -6, there is a difference between new Diff and Diff
/// therefore, it might be beneficial for us to use Diff as our main array,
/// as it allows us to reduce the problem to point update only
/// however, we gotta compute the sum using Diff array
/// it's complex af, so read it here: https://vnoi.info/wiki/algo/data-structures/fenwick.md
/// the mathematical transformation makes the problem easier to be solved by Fenwick
/// So, we create 2 bit array, 1 of which contains Diff[j] (bit1),
/// the other contains (n-j+1)* Diff[j] (bit2)
/// Then how we update bit2, when we have that (n-j+1) co-efficient
/// so, when we update Diff[j] by Delta
/// => new value in bit2 at index j is: (n-j+1)*(Diff[j] + delta)
/// => or it may be transformed into: (n-j+1)*Diff[j] + (n-j+1)*delta
/// Therefore, we only have to update bit2 by (n-j+1)* delta !!

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 2e5 + 5;

/// (n-j+1)*diff[j]   diff[j]
ll bit1[maxn]   , bit2[maxn], a[maxn];
int n, k;

void add(ll i, ll k)
{
    ll j = i;
    while(i <= n)
    {
        bit2[i] += k;
        bit1[i] += (n-j+1)*k;
        i += i & (-i);
    }
}
/// sum[i] = sigma(j = 1 -> i) [(n-j+1)*F[j]] - (n-i)*sigma(j=1->i)[F[j]]
ll sum(ll idx)
{
    ll s1 = 0, s2 = 0, tam = idx;
//    while(tam > 0)
//    {
//        s1 += bit1[tam];
//        tam -= tam & (-tam);
//    }
//    tam = idx;
    while(tam > 0)
    {
        s2 += bit2[tam];
        tam -= tam & (-tam);
    }
    //return (s1 - (n-idx)*s2);
    return s2;
}
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i)
    {
        /// l = i, r = i
        add(i, a[i] -  a[i-1]);
    }
    for(int i = 1; i <= k; ++i)
    {
        int t;
        ll x, y;
        cin >> t;
        if(t == 1)
        {
            ll k; cin >> x >> y >> k;
            add(x, k);
            add(y+1, -k);
        }
        else{
            ll k; cin >> k;
            cout << sum(k) << endl;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
