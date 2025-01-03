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

const int maxn = 2e5 + 5;

int n, k;
vector<ll> a(maxn);
map<ll, ll> cache;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }    

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == k) {
            ans += 1;
        }
        ans += cache[a[i] - k];
        cache[a[i]] += 1;
    }
    cout << ans;
}