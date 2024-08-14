//link:https://oj.vnoi.info/problem/chain2
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
const int maxn = 3e5 + 5;

int child[maxn][26], isEnd[maxn], m;
int cnt = 0;
void add(string s)
{
    int node = 0;
    for(char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
    }
    isEnd[node] = 1;
}

void traverse(int node, int dem, int &kq)
{
    if(isEnd[node]){
        ++dem;
        kq = max(kq, dem);
    }
    for(int i = 0; i < 26; ++i)
    {
        if(child[node][i] == 0) continue;
        traverse(child[node][i], dem, kq);
    }
}
void inp()
{
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        string s; cin >> s;
        add(s);
    }
    int kq = -1;
    {
        int dem = 0;
        traverse(0, dem, kq);
    }
    cout << kq;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
