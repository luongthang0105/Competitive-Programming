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

bool ok(ll max_cnt, ll deck_size, ll n, ll k) {
    ll total_add = 0LL;
    // find nearest size of n that fits deck size
    if (n % deck_size != 0) {
        ll deck_count = ceil(double(n) / double(deck_size));
        if (deck_count * deck_size - n > k) {
            return false;
        }
        total_add += deck_count * deck_size - n;
        k -= deck_count * deck_size - n;
        n = deck_count * deck_size;
    }

    ll deck_count = n / deck_size;
    
    ll least_more = max_cnt * deck_size - n;
    if (least_more > k) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        // vector<ll> cards(n);
        ll max_cnt = 0LL;
        ll total = 0LL;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            total += x;
            max_cnt = max(max_cnt, x);
        }

        ll l = 1LL, r = n;
        int ans = 0;

        while (r >= 0) {
            if (ok(max_cnt, r, total, k)) {
                ans = r;
                break;
            }
            r--;
            // ll mid = (l + r) / 2LL;
            // // cout << "mid: " << mid << endl;
            // if (ok(max_cnt, mid, total, k)) {
            //     l = mid + 1;
            //     ans = mid;
            // } else {
            //     r = mid - 1;
            // }
        }

        cout << ans << endl;
    }
}