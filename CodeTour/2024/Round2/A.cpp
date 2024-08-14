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

bool comp(int b, pll a) {
    return b < a.first;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<pll> v;
    for (int i = 0; i < n; ++i) {
        ll x, y; cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());

    vector<ll> prefSum;
    ll currPrefSum = 0;
    for (auto p : v) {
        currPrefSum += p.second;
        prefSum.pb(currPrefSum);
        // cout << p.first << " " << p.second << endl;
    }

    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        int index = upper_bound(v.begin(), v.end(), x, comp) - v.begin();
        // cout << index << endl;
        if (index == 0) cout << 0;
        else {
            cout << prefSum[index - 1];
        }
        cout << endl;
    }
}