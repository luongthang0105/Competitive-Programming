// Problem link: https://oj.vnoi.info/problem/vnoicup23_r1_b
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
const double eps = 1e-6;

double getSpeed(int t, int s) {
    if (90*s >= 10*t) {
        return 90.0 / (double)t;
    }
    else return 100.0 / ((double) t + (double) s);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int tm, sm, ty, sy;
        cin >> tm >> sm >> ty >> sy;

        double megumin = getSpeed(tm, sm);
        double yunyun = getSpeed(ty, sy);

        // cout << megumin << " " << yunyun << endl;
        if (megumin - yunyun >= eps) {
            cout << "Yunyun";
        } else if (megumin - yunyun == 0.0) 
            cout << "Draw";
        else cout << "Megumin";
        cout << endl;
    }
}