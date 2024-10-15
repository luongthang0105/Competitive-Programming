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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> hills;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                hills.pb(i);
            }
        }
        
        ll ans = 0LL;
        // cout << "ans: " << ans << endl; 
        for (int index : hills) {
            // cout << "index: " << index << " | ";
            ll cnt_left = 1LL;
            ll cnt_right = 1LL;

            for (int i = index - 1; i >= 1; --i) {
                if (a[i] > a[i - 1]) {
                    cnt_left++;
                } else break;
            }

            for (int i = index + 1; i < n - 1; ++i) {
                if (a[i] > a[i + 1]) {
                    cnt_right++;
                } else break;
            }

            // cout << cnt_left << " " << cnt_right << endl;
            ans += cnt_left * cnt_right;
        }

        cout << ans << endl;
    }
}