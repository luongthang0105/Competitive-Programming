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
const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;
ll a[maxn], n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int neg = 0, zeros = 0;
    ll res = 1LL, mxNeg = -inf;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] < 0) ++neg, mxNeg = max(mxNeg, a[i]);
        if(a[i] == 0) ++zeros;

       // res *= a[i];
    }
    if(zeros > 1) {cout << 0; return 0;}
    if(neg % 2 == 0)
    {
        if(zeros == 1) for(int i= 1; i <= n;++i) res = (res * ((a[i] != 0) ? a[i] : 1)) % inf;
        else for(int i= 1; i <= n;++i) res = (res * a[i]) % inf;
        cout << res;
        return 0;
    }
    else{
        if(zeros == 1) cout << 0;
        else
        {
            for(int i = 1; i <= n; ++i) res = (res * ((a[i] != mxNeg) ? a[i] : 1)) % inf;
            cout << res;
        }

    }
    return 0;
}


/*
int chec( int i )
{
    if( i <= 1 ) return 0;
    if( i <= 3 ) return 1;

    if( i % 2 == 0 | i % 3 == 0 ) return 0;

    for(int j = 5; j <= sqrt(i); j+=6)
        if(i % j == 0 || i % (j+2) == 0 ) return 0;
    return 1;
}

int gcd(int a, int b)
{
    while(b > 0)
    {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int xorr(int a, int b)
{
    a ^= b;
    return a;
}
int andd(int a, int b)
{
    a &= b;
    return a;
}
*/
