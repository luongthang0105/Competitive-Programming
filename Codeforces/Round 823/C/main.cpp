//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;

int t;
string s;
void solve()
{
    vector<int> g[10], cnt(10, 0);
    cin >> s;
    int mi = 10, n = s.size();

    for(int i = 0; i < n; ++i)
    {
        g[s[i]-'0'].pb(i);
        mi = min(mi, s[i] -'0');
        cnt[s[i]-'0']++;
    }
    int left = 0;
    vector<int> save(10,0);
    string ans = "";

    while(left < n-1)
    {
        int idx = 0;
        for(int i = left; i <= g[mi].back(); ++i)
        {
            if(s[i]-'0' != mi)
                save[min(9, s[i]-'0'+1)]++;
            else save[s[i]-'0']++;
            cnt[s[i]-'0']--;
        }
        left = g[mi].back() + 1;
        ///re-find new mi
        mi = 10;
        for(int i = 0; i <= 9; ++i)
            if(cnt[i] != 0)
            {
                mi = i;
                break;
            }
    }
    if(left != n)
        save[s[n-1]-'0']++;
    for(int i = 0; i <= 9; ++i)
    {
        for(int j = 0; j < save[i]; ++j)
            ans += char(i+48);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> t;
    //t = 1;
    while(t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}

