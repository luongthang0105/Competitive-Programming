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
const ll mod = 1e9 + 7;

int t;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> s;
        ll n = s.size();
        vector<int> v[26];
        for(int i = 0; i < n; ++i)
        {
            v[s[i]-'a'].pb(i+1);
        }

        ll sum = 0LL;
        for(int i = 0 ; i < 26; ++i)
        {
            ll k = v[i].size();
            for(int j = 0; j < k; ++j)
            {
                ll start, endd;
                if(j == 0) start = 1;
                else start = v[i][j-1]+1;
                if(j == k-1) endd = n;
                else endd = v[i][j+1]-1;
                sum += (v[i][j]-start+1)*(endd-v[i][j]+1);
            }
        }
        cout << sum << endl;
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
