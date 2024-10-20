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

ll valid_ans(ll ans, ll a, ll b, ll c) {
    return ((ans % a == 0) + (ans % b == 0) + (ans % c == 0)) == 2;
}
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

ll runAns() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    
    {
        db lcm_ab = (a*b)/__gcd(a,b);
        db lcm_bc = (c*b)/__gcd(c,b);
        db lcm_ac = (a*c)/__gcd(a,c);
        db lcm_abc = (lcm_ab*c)/__gcd((ll)lcm_ab, (ll)c);

        ll l = 1LL, r = 1e18;
        bool hasAns = 0;
        // cout << f(19, lcm_ab, lcm_ac, lcm_bc, lcm_abc) << endl;
        int iter = 0;
        while (l <= r && iter <= 70) {
            // cout << "l: " << l << ", r: " << r << endl;
            iter++;
            ll mid = l + (r - l) / 2LL;
            ll f_mid = f(mid, lcm_ab, lcm_ac, lcm_bc, lcm_abc);
            // cout << "l: " << l << " r: " << r << " mid: " << mid << " f: " << f_mid << endl;
            if (f_mid == n) {
                hasAns = 1;
                r = mid;
            } else if (f_mid < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (hasAns) {
            return r; 
        }
        return -1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cout << runAns() << endl;
}