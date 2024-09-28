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

bool is_int(double x) {
    return x == trunc(x);
}

bool is_in_bound(double x, int n) {
    return (0 <= x) && (x < n);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        vector<ll> points(n);
        for (int i = 0; i < n; ++i) cin >> points[i];

        for (int i = 0; i < q; ++i) {
            ll k;
            cin >> k;
            
            ll count = 0LL;
            
            ll delta1 = (n-1)*(n-1) + 4*(n-1-k);
            ll delta2 = n*n - 4*k;
            
            if (delta1 >= 0) {
                double x1 = (-(n-1) - sqrt(delta1)) / (2 * -1);
                double x2 = (-(n-1) + sqrt(delta1)) / (2 * -1);

                if (is_int(x1) && is_in_bound(x1, n)) {
                    count += 1;
                }

                if (x1 != x2 && is_int(x2) && is_in_bound(x2, n)) {
                    count += 1;
                }
            }

            if (delta2 >= 0) {
                double x1 = (-n - sqrt(delta2)) / (2 * -1);
                double x2 = (-n + sqrt(delta2)) / (2 * -1);

                if (is_int(x1) && is_in_bound(x1, n)) {
                    count += points[x1] - points[x1 - 1] - 1;
                }

                if (x1 != x2 && is_int(x2) && is_in_bound(x2, n)) {
                    count += points[x2] - points[x2 - 1] - 1;
                }
            }
            cout << count << " ";
        }
        cout << endl;
    }
}