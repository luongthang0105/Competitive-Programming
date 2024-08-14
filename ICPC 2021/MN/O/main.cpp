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
int n;
ll cnt = 0LL;
unordered_map<int, ll> m1, m2;
map<pii, ll> m;
void solve()
{
    cin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        m[{x,y}] += 1LL;
        m1[x] += 1LL;
        m2[y] += 1LL;
    }
    for(auto i : m1)
        cnt += i.se*(i.se-1LL)/2LL;
    for(auto i : m2)
        cnt += i.se*(i.se-1LL)/2LL;
    for(auto i : m)
        cnt -= i.se*(i.se-1LL)/2LL;
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}

