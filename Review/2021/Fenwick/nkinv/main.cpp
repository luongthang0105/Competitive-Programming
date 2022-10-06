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
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 6e4;
ll bit[maxn+5];
void add(int x){
    while(x <= maxn){
        bit[x] += 1LL;
        x += x & (-x);
    }
}
ll sum(int x){
    ll kq = 0;
    while(x > 0){
        kq += bit[x];
        x -= x & (-x);
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    ll kq = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        kq += sum(maxn) - sum(x);
        add(x);
    }
    cout << kq;
    return 0;
}
