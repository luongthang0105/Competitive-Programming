// Problem link: https://codeforces.com/contest/670/problem/D1
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

ll n, k;
vector<ll> needs;
vector<ll> has;

bool test(ll numCookies) {
    ll ingredientNeeds = 0LL;
    for (int i = 0; i < n; ++i) {
        ll diff = has[i] - needs[i] * numCookies;
        ingredientNeeds += diff > 0 ? 0 : -diff;
        if (ingredientNeeds > k) return false;
    }
    return k >= ingredientNeeds;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> k;
    needs = vector<ll>(n);    
    has = vector<ll>(n);

    for (int i = 0 ; i < n; ++i) {
        cin >> needs[i];
    }

    ll maxHas = 0;
    for (int i = 0 ; i < n; ++i) {
        cin >> has[i];
        maxHas = max(maxHas, has[i]);
    }

    ll low = 0, high = k + maxHas;
    ll ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (test(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
}