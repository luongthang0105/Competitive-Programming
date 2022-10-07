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
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double pi = 3.141592654;

double xa, ya,xb,yb,xc,yc,r,p;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> r >> p;

    double shiftx = -xc, shifty = -yc;
    xa += shiftx; ya += shifty;
    xb += shiftx; yb += shifty;
    xc = yc = 0;

    double a, delta, b;
    double x1,y1, x2, y2;
    /// y = ax + b
    if(xb != xa)
    {
       a = (yb - ya) / (xb - xa);
       b = ya - a * xa;
       delta = r*r*(a*a+1.0) - b*b;
       if(delta <= 0){
            cout << "NO";
            return 0;
       }
       x1 = (-a*b + sqrt(delta)) / (a*a+1);
       x2 = (-a*b - sqrt(delta)) / (a*a+1);

       y1 = x1*a + b; y2 = x2*a + b;
    }
    ///truong hop x = k (duong thang dung')
    else{
        x1 = x2 = xb;
        y1 = -sqrt(r*r - x1*x1);
        y2 = sqrt(r*r - x2*x2);
        if(x1 == x2 && y1 == y2) {cout << "NO"; return 0;}
    }
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    double hlen = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) / 2.0;
    double goc = 2.0*pi - asin(hlen/r) * 2.0;
    ///tinh dien tich hinh tron khuyet
    double partial_circle = goc/(2*pi) * (pi * r * r);
    /// tinh duong cao va dien tich tam giac
    double H = sqrt(r*r - hlen*hlen);
    double Tri =  H * (hlen);

    /// tinh phan tram dien tich cua phan^` nho?
    double cut = 1.0 - (Tri + partial_circle) / (pi*r*r);
    cut *= 100.0;
    if(abs(cut - p) <= 5.0) cout << "YES";
    else cout << "NO";
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
