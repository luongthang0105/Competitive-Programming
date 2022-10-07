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
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

void io()
{
    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);
}

int t=1, n , m, k;
string s[maxn];
struct Point{
    double x,y;
};
Point v[5];

double cross(Point a, Point b, Point c){
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
bool cmp(Point a, Point b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
void convexhull()
{
    vector<Point> Up(5), Down(5);
    int k = 0;
    /// lower -> ccw -> cross > 0
    for(int i = 1; i <= 4; ++i)
    {
        while(k >= 2 && cross(Down[k-2], Down[k-1], v[i]) <= 0)
            --k;
        Down[k] = v[i];
        ++k;
    }
    Down.resize(k);
    k = 0;
    ///up -> cw -> cross < 0
    for(int i = 1; i <= 4; ++i)
    {
        while(k >= 2 && cross(Up[k-2], Up[k-1], v[i]) >= 0)
            --k;
        Up[k] = v[i];
        ++k;
    }
    Up.resize(k);
    if(Up.size() + Down.size() - 2 == 4) cout << "YES";
    else cout << "NO";

}
void solve()
{
    for(int i = 1; i <= 4; ++i) cin >> v[i].x >> v[i].y;
    sort(v+1,v+5,cmp);
    for(int i = 2; i <= 4; ++i) if(v[i].x == v[i-1].x && v[i].y == v[i-1].y) {
        cout << "NO";
        return;
    }
    /// a b c d
    /// vec(ab) = (b.x-a.x, b.y-a.y) vec(ad) = (d.x-a.x, d.y-a.y)
    ///
    convexhull();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    //io();
    cin >> t;
    while(t--)
    {
        solve();
        cout << endl;
        fflush(stdout);
    }
    return 0;
}

/*

int chec( int i )
{
    if( i <= 1 ) return 0;
    if( i <= 3 ) return 1;

    if( i % 2 == 0 | i % 3 == 0 ) return 0;

    for(int j = 5; j <= sqrt(i); j+=6)
        if(i % j == 0 || i % (j+2) == 0 ) return 0;
    return 1;
}

int gcd(int a, int b)
{
    while(b > 0)
    {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int xorr(int a, int b)
{
    a ^= b;
    return a;
}
int andd(int a, int b)
{
    a &= b;
    return a;
}

*/
