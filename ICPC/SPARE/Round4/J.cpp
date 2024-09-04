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

const int maxn = 1e2 + 5;

vector<int> items;
double ans = INT_MAX;
double eps = 1e-18;
double INF = 200;

class Point {
    public:
        double x;
        double y;
        Point(double angle) {
            this->x = getX(angle);
            this->y = getY(angle);
        }
        Point(double x, double y) {
            this->x = 0;
            this->y = 0;
        }
        double getDist(Point other) {
            return sqrt(square(x - other.x) + square(y - other.y));
        }
        void print() {
            cout << x << " " << y << endl;
        }
    private:
        double getX(double angle) {
            return cos(angle);
        }
        double getY(double angle) {
            return sin(angle);
        }
        double square(double a) {
            return a*a;
        }
};
vector<vector<Point>> graph(maxn);

void print(vector<vector<double>> dp) {
    cout << "Size: " << dp.size() << " " << dp[0].size() << endl;
    for (vector v : dp) {
        for (double i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        items.push_back(x);
    }
    double m;
    cin >> m;
    vector<int> stations(m);
    vector<Point> stationPoints;
    for (int i = 0; i < m; ++i) {
        cin >> stations[i];
    } 

    double startAngle = M_PI / 2.0;
    double angleDiff = 2.0 * M_PI / m;
    for (int i = 0; i < m; ++i) {
        stationPoints.pb(Point(startAngle));
        startAngle -= angleDiff;
    }

    double ans = INF;
    vector<vector<double>> dp(n, vector<double>(m, INF));

    // init with i = 0
    for (int j = 0; j < m; ++j) {
        if (stations[j] == items[0]) {
            dp[0][j] = 1.0;
        }
    }

    for (int i = 1; i < n; ++i) {
        int exercise = items[i];
        for (int j = 0; j < m; ++j) {
            if (exercise != stations[j]) continue;
            
            double minDist = INF;
            for (int k = 0; k < m; ++k) {
                minDist = min(minDist, dp[i - 1][k] + stationPoints[k].getDist(stationPoints[j]));
            }

            dp[i][j] = minDist;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    for (int j = 0; j < m; ++j) {
        ans = min(ans, dp[n - 1][j]);
    }
    cout << setprecision(6) << fixed << ans;
}