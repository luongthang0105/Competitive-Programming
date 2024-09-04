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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    int l = 0, r = n - 1;
    vector<bool> check(n, false);

    while (l < n && r >= 0 && l < r) {
        if (a[l] + a[r] <= k) {
            count += 1;
            check[l] = check[r] = true;
            l += 1;
            r -= 1;
        } else {
            count += 1;
            check[r] = true;
            r -= 1;
        }
    }
    cout << count + !check[l];
}