// Problem link: https://oj.vnoi.info/problem/bedao_r20_a
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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll x = sqrt(n);
        if (x * x == n) {
            ll count = 0;
            ll sqrtN = trunc(sqrt(n));
            // cout << sqrtN << endl;
            for (ll i = 2LL; i <= sqrt(sqrtN); i += 2LL) {
                if (sqrtN % i == 0 && (sqrtN / i) % 2 == 0) {
                    if (i * i != sqrtN) {
                        count += 2;
                    } else count += 1;

                    // cout << i << " " << sqrtN/i << endl;
                }
            }
            cout << count << endl;
        } else {
            cout << 0 << endl;
        }
    }
}