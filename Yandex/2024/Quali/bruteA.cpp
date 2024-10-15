// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "A" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

int f(int a, int b, int c, int n) {
    int lcm_ab = (a*b)/__gcd(a,b);
    int lcm_bc = (c*b)/__gcd(c,b);
    int lcm_ac = (a*c)/__gcd(a,c);

    if (lcm_ab == lcm_bc && lcm_bc == lcm_ac) return -1;
    
    int cnt = 0;
    int i = 1;
    while (cnt < n) {
        int div_cnt = (i % a == 0) + (i % b == 0) + (i % c == 0);
        if (div_cnt == 2) {
            cnt++;
        }
        i++;
    }
    return i - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".ans", "w", stdout);
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << f(a,b,c,n) << endl;    
}