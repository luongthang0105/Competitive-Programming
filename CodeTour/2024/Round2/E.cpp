// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

ll expo(ll x, ll p, ll mult) {
    if (p == 1) return x;
    
    ll halfExpo = expo(x, p / 2, mult);
    
    if (halfExpo == -1 || halfExpo >= mult) return -1;

    if (p % 2 == 0) {
        return halfExpo * halfExpo;      
    }
    if (p % 2 == 1) {
        if (halfExpo * x >= mult) return -1;
        return halfExpo * halfExpo * x;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    ll mult = 1LL;
    for (int i = 0; i < n; ++i) {   
        ll x; cin >> x;
        mult *= x;
    }
    // cout << mult << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x, p;
        cin >> x >> p;
        // ll getExpo = expo(x, p, mult);
        // cout << getExpo << endl;
        // if (getExpo == -1) ans += '0';
        // else if (mult % getExpo == 0) ans += '1';
        // else ans += '0';
        
        ll temp = mult;
        if (x == 1) {
            cout << 1;
            continue;
        }
        while (temp % x == 0 && p > 0) {
            p--;
            temp /= x;
        }
        if (p > 0) cout << 0;
        else cout << 1;
    }
}