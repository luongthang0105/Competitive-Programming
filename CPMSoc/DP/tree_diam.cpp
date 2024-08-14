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

const int maxn = 2e5 + 5;
vector<int> graph[maxn];
int diam(int u) {
    
    for (int v : graph[u]) {

    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    cout << diam(1);
}