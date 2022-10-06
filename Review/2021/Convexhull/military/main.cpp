#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
using namespace std;

typedef int ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;
const int maxn = 1e5 + 5;

struct vt{
    int x, y;
};

int cross(vt a, vt b, vt c)
{
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
bool check(vector<vt> A)
{
    if(A.size() <= 2) return 1;
    int ok = 1;
    for(int i = 1; i < A.size(); ++i)
        if(A[i].x != A[i-1].x){ ok = 0; break;}
    if(ok) return 1;

    for(int i = 1; i < A.size(); ++i)
        if(A[i].y != A[i-1].y){ ok = 0; break;}
    return ok;
}
bool cvhl(vt a[], int n, set<pii>& s, int& dem){
    vector<vt> Up(n+5), Down(n+5);

    int k = 0;
    for(int i = 0; i < n; ++i)
    {
        while(k >= 2 && cross(Down[k-2], Down[k-1], a[i]) < 0)
            k--;
        Down[k] = a[i];
        k++;
    }
    Down.resize(k); k = 0;
    for(int i = 0; i < n; ++i)
    {
        while(k >= 2 && cross(Up[k-2], Up[k-1], a[i]) > 0)
            k--;
        Up[k] = a[i];
        k++;
    }
    Up.resize(k);
    for(int i = Up.size() - 2; i > 0; --i)
        Down.pb(Up[i]);

    if(check(Down)){ dem--; return 0;}
    else{
        for(vt i : Down) s.erase({i.x, i.y});
        return 1;
    }
}
int n;
set<pii> s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
    }
    int dem = 0;
    while(true){
        ++dem;
        vt a[s.size() + 1];
        int i = 0;
        for(pii v : s)
            a[i].x = v.fi, a[i].y = v.se, ++i;
        if(cvhl(a, i, s, dem) == 0){
            cout << dem;
            break;
        }
    }
    return 0;
}
