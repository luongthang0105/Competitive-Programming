#include <bits/stdc++.h>
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
const ll inf = 1e9 + 7;
ll sz[maxn], par[maxn], fac[maxn];
int m, n;

int find_set(int x)
{
    if(x == par[x]) return x;
    int p = find_set(par[x]);
    par[x] = p;
    return p;
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) par[i] = i, sz[i] = 1;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        union_set(x,y);
    }
    ll res = 0LL;
    fac[0] = 1LL;
    for (ll i=1; i<=n; ++i)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=inf;
    }
    for(int i = 0; i <= n; ++i)
    {
        if(par[i] == i && sz[i] > 2){
            res = (res + fac[sz[i]])%inf;
        }
        //cout << par[i] << " " << i << " " << sz[i] <<endl;
    }
    cout << res;
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
