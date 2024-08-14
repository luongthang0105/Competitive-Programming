//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob ""
#define endl "\n"
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;


void kmp()
{
    string s;
    n = s.size();
    vector<int> p(n+1);
    for(int i = 1; i < n; ++i)
    {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }
}

void kc_string()
{
    int k = s.size(), l = t.size();
    for(int i = 0; i <= k; ++i)
        dp[0][i] = i;
    for(int i = 1; i <= l; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(j == 0) dp[(i%2)][j] = j;
            else if(t[i-1] == s[j-1]) dp[(i%2)][j] = dp[(i-1)%2][j-1];
            else dp[(i%2)][j] = 1 + min3(dp[(i-1)%2][j], dp[(i%2)][j-1], dp[(i-1)%2][j-1]);
        }
    }
    return dp[(l%2)][k];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
