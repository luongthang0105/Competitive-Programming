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
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 4e5 + 5;

int cnt = 0, child[maxn][26], isEnd[maxn];
ll k, dp[300005], n;
string s, t;

void add(string& s)
{
    int node = 0;
    for(int i = s.size()-1; i >= 0; --i)
    {
        int x = s[i] - 'a';
        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
    }
    isEnd[node] = 1;
}

int Find(char& c, int& node)
{
    {
        int x = c - 'a';
        if(child[node][x] == 0) return -1;
        node = child[node][x];
    }
    return isEnd[node];
}
void inp()
{
    cin >> s;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> t;
        add(t);
    }
}

void solve()
{
///dp[i]: so cach tao thanh doan tu 0->i tu` list
    for(int i = 0; i < s.size(); ++i)
    {
        int t = 0;
        for(int j = i; j >= 0; --j)
        {
/// xet doan tu j -> i, neu co' trong list -> doan tu j->i ket hop duoc voi doan tu 0->j-1
            int check = Find(s[j], t);
            if(check == 1){
                if(j == 0) dp[i] += 1;
                else dp[i] = (dp[i] + dp[j-1]) % 1337377;
            }else if(check == -1) break;
        }
    }
    cout << dp[s.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
