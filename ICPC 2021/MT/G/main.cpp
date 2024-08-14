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
const int maxn = 5e5 + 5;
const ll mod = 1e9 + 7;

int a[maxn], delta[maxn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    string s;
    cin >> s;
    for(int i = 0;i < s.size(); ++i) a[i] = s[i]-'A';
    int k;
    cin >> k;
    while(k--)
    {
        int n,x, y;
        cin >> n >> x >> y;
        delta[x-1] += n;
        delta[y] -= n;
    }
    int add = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        add += delta[i];
        cout << char((a[i] + add) % 26 + ('A'));
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
