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

const int maxn = 1e5 + 5;
ld eps = 1e-10;

class Point {
    public:
        ld x;
        ld y;
        ld z;
        ld dist;
        Point(ld x, ld y, ld z) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->dist = calcDist();
        }
    private:
        ld calcDist() {
            return x*x + y*y + z*z;
        }
};

int countClouds(ld radius, vector<Point> points) {
    int count = 0;
    for (Point p : points) {
        if (radius*radius - p.dist > eps) {
            count++;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<Point> points;
    for (int i = 0; i < n; ++i) {
        ld x, y, z;
        cin >> x >> y >> z;
        Point newPoint = Point(x, y, z);
        points.push_back(newPoint);
    }
    
    ld l = 1, r = 1e18;
    ld ans;
    while (true) {
        ld mid = (l + r) / 2.0;
        if (countClouds(mid, points) >= k) {
            r = mid - 1;
            if (abs((mid) - (ans)) < eps) break;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << setprecision(7) << fixed << ans;
}