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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int sum = mx;
            if (a[j] == mx) {
                for (int i = j + 2; i < n; i += 2) {
                    sum += 1;
                }

                for (int i = j - 2; i >= 0; i -= 2) {
                    sum += 1;
                }
                ans = max(ans, sum + 1);
            }
        }
        cout << ans << endl;
    };
}