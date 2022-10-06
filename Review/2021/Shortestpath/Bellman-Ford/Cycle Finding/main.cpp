///link: https://cses.fi/problemset/task/1197
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
const int maxn = 3e3 + 5;
const int maxm = 5e3 + 5;

struct Edge{
    int u, v;
    ll w;
};
Edge E[maxm];
ll d[maxn], trace[maxn];
int m, n;

///luu y: bai nay la tim 1 neg_cycle bat ki`
/// vi` vay, ta ko cho d[s] = 0 vi chu trinh nay
/// co the ko reachable tu` s
/// instead, we make up an imaginary vertex: A'
/// the distance from A' to any other vertices is 0
/// therefore, we manage to make this a single source problem
/// (but with an imaginary vertex)
/// clear explanation at: https://youtu.be/kZfm68XKC58?t=213
void bellford(){

    //fill(d,d + maxn, INT_MAX);
    fill(trace, trace + maxn, -1);
    //d[1] = 0;
    int negStart;
    /// run n loops instead of n-1
    ///the nth loop helps us identify a node that's still minimizing value
    for(int i = 1; i <= n; ++i)
    {
        negStart = -1;
        for(int j = 1; j <= m; ++j){
            int u = E[j].u, v = E[j].v;
            ll w = E[j].w;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                trace[v] = u;
                negStart = v;
            }
        }
    }

    //int negStart = check_neg();
    if(negStart == -1) {cout << "NO"; return;}
    for(int i = 1; i <= n; ++i)
        negStart = trace[negStart];

    vector<int> p;
    int tmp = negStart;
    while(trace[negStart] != tmp){
        p.pb(negStart);
        negStart = trace[negStart];
    }
    cout << "YES" << endl;
    p.pb(negStart);
    reverse(p.begin(), p.end());
    cout << tmp << " ";
    for(int i : p) cout << i << " ";
}
void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    bellford();
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
