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

int Z[maxn], n;
int candidates[1000005];
string s, p;
void ZZ(){
    int l = 0, r = 0;
    for(int i = 1; i <= n - 1; ++i){
        if(i > r){
            r = l = i;
            while(r < n && p[r] == p[r - l]) ++r;
            Z[i] += r - l;
            r--;
        }else{
            int k = i - l;
            if(Z[k] + i - 1 < r) Z[i] = Z[k];
            else{
                l = i;
                while(r < n && p[r] == p[r - l]) ++r;
                Z[i] += r - l;
                r--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);

    cin >> s;
    p = s + "$" + s;
    n = p.size();
    ZZ();

    int mark = -1, spt = 0;

    for(int i = n - 1; i > int(s.size()) + 1; --i){
        if(i + Z[i] - 1 == n - 1)
        {
            ++spt;
            candidates[spt] = n - i;
            mark = 1;
        }
    }

    if(mark == -1) {cout << "Just a legend";}
    else{
        int ok = 0, len = 0, mx = -1, idx = spt;
        for(int i = s.size() + 1 + 1; i <= n-1 && idx > 0; ++i){
        {
            int k = candidates[idx];
            if(mx >= k)
            {
                len = k;
                ok = 1;
                break;
            }
            if(Z[i] != 0) mx = max(mx, Z[i]);
            if(i == n - k)
                idx--;
        }
    }
        if(!ok) cout << "Just a legend";
        else{
            for(int i = n-len; i <= n-1; ++i)
                cout << p[i];
        }
    }
    return 0;
}
