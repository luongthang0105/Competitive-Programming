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

ll n;
vector<ll> a(maxn);
vector<ll> occurrences(maxn);
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) a[i] = (a[i - 1] + a[i]);
        while (a[i] < 0) {
            a[i] += n * n;
        }
        a[i] %= n;
    }

    for (int i = 0 ; i < n; ++i) {
        occurrences[a[i]] += 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        // cout << i << " " << occurrences[i] << endl;
        if (i == 0) ans += occurrences[i];
        if (occurrences[i] == 1) continue;
        ans += occurrences[i] * (occurrences[i] - 1) / 2;
    }
    cout << ans;
}