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
    int n;
    ll target;
    cin >> n >> target;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        a[i] = {x, i + 1};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (a[l].first + a[r].first + a[i].first == target) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            } else if (a[l].first + a[r].first + a[i].first < target) {
                l++;
            } else r--;
        }
    }
    cout << "IMPOSSIBLE";
}