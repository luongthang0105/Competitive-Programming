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
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

int n;
ll sum = 0LL;
vector<int> check;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i]; sum += a[i];
    }
    cin >> s;
    ll pre_s = -1, ok = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(sum == 0) cout << sum;
        else if(s[i] == '0')
        {
            if(!ok)
            {
                for(int j = 0; j < n; ++j)
                    if(a[j] % 2 == 0) a[j] /= 2, sum -= a[j];
                if(sum == pre_s)
                    ok = 1;
            }
            cout << sum;

        }
        else{
            ok = 0;
            if(i-1 != 0 && s[i-1] == '1')
                cout << sum;
            else{
                for(int j = 0; j < n; ++j)
                    if(a[j] % 2 == 1) a[j] -= 1, sum -= 1;
                cout << sum;
            }
        }
        //cout << " " << check[i] << " " << (check[i] == sum) ;
        pre_s = sum;
        cout << endl;
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
