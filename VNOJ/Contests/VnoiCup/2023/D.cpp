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
const int maxk = 1e2 + 5;
int n, k;
ll dp[maxn][maxk];
vector<int> times;
string t, s;
vector<int> countS(26, 0), countT(26, 0);

bool sameCount() {
    for (int i = 0; i < 26; ++i) {
        if (countS[i] != countT[i]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> k;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        times.pb(a);
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int stringIndex = i - 1;

        countS[s[stringIndex] - 'a'] += 1;
        countT[t[stringIndex] - 'a'] += 1;
        
        if (sameCount()) {
            for (int j = 1; j <= k; ++j) {
                
                for (int z = 0; z < i - 1; ++z) {
                    if (dp[z][j - 1] == INT_MAX) continue;
                    dp[i][j] = min(dp[i][j], dp[z][j - 1] + rangeSum(z, ))
                }
            }
        }
    }
}
