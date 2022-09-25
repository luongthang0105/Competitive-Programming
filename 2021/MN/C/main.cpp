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
typedef pair<char, char> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;
string s;
int k;
bool cmp(pii a, pii b)
{
    if(a.fi < b.fi) return true;
    else if(a.fi == b.fi) return a.se <= b.se;
    return false;
}
void solve()
{
    cin >> s;
    cin >> k;
    int n = s.size();
    pair<char ,char> candidate = {'z', 'z'};
    for(int i = 0; i < n-1; ++i)
    {
        pii t = {min(s[i], s[i+1]), max(s[i], s[i+1])};
        candidate = min(candidate, t, cmp);
    }
    for(int i = 0; i < k; ++i)
    {
        if(i % 2 == 0) cout << candidate.fi;
        else cout << candidate.se;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}

