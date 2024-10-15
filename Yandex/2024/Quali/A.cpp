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

ll f(ll num, db lcm_ab, db lcm_ac, db lcm_bc, db lcm_abc) {
    ll cnt = 0LL;
    cnt += (trunc(num / lcm_ab) - trunc(num / lcm_abc));
    if (lcm_bc != lcm_ab) {
        cnt += (trunc(num / lcm_bc) - trunc(num / lcm_abc));
    }
    if (lcm_ac != lcm_ab && lcm_ac != lcm_bc) {
        cnt += (trunc(num / lcm_ac) - trunc(num / lcm_abc));
    }

    // if (num == 13) cout << "scnt of 13: " << cnt << endl;
    return cnt;
}

int runAns() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    
    {
        db lcm_ab = (a*b)/__gcd(a,b);
        db lcm_bc = (c*b)/__gcd(c,b);
        db lcm_ac = (a*c)/__gcd(a,c);
        db lcm_abc = (lcm_ab*c)/__gcd((ll)lcm_ab, (ll)c);

        ll l = 1LL, r = 1e18;
        ll ans = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2LL;
            ll f_mid = f(mid, lcm_ab, lcm_ac, lcm_bc, lcm_abc);
            if (f_mid == n) {
                ans = mid;
                break;
            } else if (f_mid < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans == -1) {
            return ans; 
        }
        // cout << ans << endl;
 
        if (ans % (ll)lcm_abc == 0) {
            ans -= min(lcm_ab, min(lcm_abc, lcm_ac));
        } else if (ans % ll(lcm_ab) != 0 && ans % ll(lcm_ac) != 0 && ans % ll(lcm_bc) != 0){
            // ll min_mod = min(ans % ll(lcm_ab), min(ans % ll(lcm_ac), ans % ll(lcm_bc)));
            // ans -= min_mod;

            set<db> v = {lcm_ab, lcm_bc, lcm_ac};
            // cout << ans << endl;
            while (true) {
                int cnt = (ans % ll(lcm_ab) == 0) + (ans % ll(lcm_ac) == 0) + (ans % ll(lcm_bc) == 0);
                if (v.size() != 3) {
                    if (cnt == 2 || cnt == 1) break;
                } else if (cnt == 1) break;
                // cout << ans << " " << cnt << endl;
                ans--;
            }
        }
        return ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cout << runAns() << endl;
}