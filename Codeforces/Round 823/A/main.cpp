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

int t;

void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0, orbit[100];
    for(int i = 0; i <= 100; ++i) orbit[i] = 0;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        orbit[x] += 1;
    }
    for(int i = 0; i <= 100; ++i)
    {
        if(orbit[i] != 0)
            sum += min(orbit[i], k);
    }
    cout << sum;
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

