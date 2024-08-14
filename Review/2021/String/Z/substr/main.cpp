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
const int maxn = 2e6 + 5;

int Z[maxn];
string s, t;
void solve()
{
    int n;
    cin >> s >> t;
    n = s.size() + t.size() + 1;
    s = t + "$" + s;

    int l = 0, r = 0;
    for(int i = 1 ; i <= n - 1; ++i){
        if(i > r){ ///which means there are no "gud" prefix passing thru index i
            l = r = i;
            while(r < n && s[r] == s[r - l])
                ++r;
            Z[i] += r - l;
            r--;
        }
        else{ ///r >= i, which means we have "gud" prefix
            int k = i - l;
            if(Z[k] + i - 1 < r) Z[i] = Z[k];
            else{
                l = i;
                while(r < n && s[r] == s[r-l])
                    ++r;
                Z[i] = r - l;
                r--;
            }
        }
    }
    vector<int> p;
    for(int i = t.size()+1; i <= n - 1; ++i){
        if(Z[i] == t.size()){
            cout << (i - t.size()) << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    solve();
    return 0;
}
