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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(k + 5, 0);
        for (int i = 0; i < k; ++i) {
            int b, c;
            cin >> b >> c;
            cnt[b] += c;
        }
        sort(cnt.begin(), cnt.end());
        int ans = 0;
        for (int i = max(0, (int)cnt.size() - n); i < cnt.size(); ++i) {
            ans += cnt[i];
        }
        cout << ans << endl;
    }
}