// Problem link: https://codeforces.com/problemset/problem/2002/C
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

ll sqr(ll a) {
    return a*a;
}
ll calculateDist(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll timeTravelled = (sqr(p1.first - p2.first) + sqr(p1.second - p2.second));
    return timeTravelled;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> coords(n);
        for (int i = 0; i < n; ++i) {
            cin >> coords[i].first >> coords[i].second;
        }
        pair<ll, ll> start, dest;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;

        ll dist = calculateDist(start, dest);

        bool ok = true;
        // cout << setprecision(30) << fixed;
        // cout << dist << endl;
        for (int i = 0; i < n; ++i) {
            ll distFromCirc = calculateDist(dest, coords[i]);
            // cout << distFromCirc << endl;
            if (distFromCirc <= dist) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}