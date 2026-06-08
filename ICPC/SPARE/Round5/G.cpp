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

int sum(int x)
{
    return x * (x + 1) / 2;
}

const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    int max_k = 1;
    string s;
    cin >> n;
    cin >> s;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    while (sum(max_k) < n)
    {
        max_k += 1;
    }

    vector<vector<ll>> dp(n + max_k + 1, vector<ll>(max_k + 1, 0));
    ll ans = 0;
    dp[1][0] = 1;
    for (int i = 1; i <= max_k; ++i)
    {
        dp[1][i] = -1;
    }

    for (int i = 2; i <= n + max_k; ++i)
    {
        if (s[i - 1] == '#')
        {
            fill(dp[i].begin(), dp[i].end(), -1);
            continue;
        }
        for (int k = 0; k <= max_k; ++k)
        {
            if (i > n && i - (k + 1) > n)
            {
                dp[i][k] = -1;
                continue;
            }
            if (k != 0 && i - (k + 1) >= 1 && s[i - (k + 1) - 1] != '#' && dp[i - (k + 1)][k - 1] != -1)
            {
                dp[i][k] = (dp[i - (k + 1)][k - 1]);
            }
            if (i <= n + 1 && s[i - 1 - 1] != '#' && dp[i - 1][k] != -1)
            {
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % MOD;
            }

            if (dp[i][k] == 0)
            {
                dp[i][k] = -1;
            }
            else if (i > n)
            {
                ans = (ans + dp[i][k]) % MOD;
            }
        }
    }
    for (int k = 0; k <= max_k; ++k)
    {
        for (int i = 1; i <= n + max_k; ++i)
        {
            cout << dp[i][k] << "\t";
        }
        cout << endl;
    }
    cout << ans;
}