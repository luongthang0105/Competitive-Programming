//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back#
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
vector<int> p;
int dem = 0, d = 0;
int check[10];
bool checker()
{
    int cnt = 0;
    return check[6];
}
void dq(int n)
{
    if(p.size() == n)
    {
        if(checker())
        {
            ++dem;
            ++d;
            for(int i : p) cout << i; cout << endl;
        }
        return;
    }
    else
    {
        for(int i = 1; i <= 7; ++i)
        {
            //if(p.empty() && i == 0) continue;
            if(check[i]) continue;
            p.eb(i);
            check[i] = 1;
            dq(n);
            check[i] = 0;
            p.pop_back();
        }
    }
}
void solve()
{
    for(int i = 4; i <= 4; ++i)
    {
        d = 0;
        dq(i);
    }
    cout << dem;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);
    freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
