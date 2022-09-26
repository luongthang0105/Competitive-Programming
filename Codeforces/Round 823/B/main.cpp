//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
#include <iomanip>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;

const int maxn = 1e5 + 5;

int t;
int n;
double timee[maxn], a[maxn];
double f(double x)
{
    double mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        mx = max(mx, double(timee[i] + abs(x - a[i])));
    }
    return mx;
}
double max_f(double left, double right) {

	int N_ITER = 100;

	for (int i = 0; i < N_ITER; i++) {

		double x1 = left + (right - left) / 3.0;
		double x2 = right - (right - left) / 3.0;

		if (f(x1) < f(x2)) right = x2;
		else left = x1;
	}
	return left;
}

void ternary_search()
{
    double mx= 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> timee[i];
    }
    cout << setprecision(20) << max_f(0, mx) ;
};
void bin_search()
{
    double mi = double(inf);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> timee[i], mi = min(mi, timee[i]);

    double l = mi, r = 200000000.0, meet = -1;
    double final_l=l, final_r=r;
    for(int j = 0; j <= 100; ++j)
    {
        double mid = (l + r) / 2; ///meeting time
        double max_left = 0.0, min_right = double(inf);
        for(int i = 1; i <= n; ++i)
        {
            max_left = max(max_left, a[i] - (mid - timee[i]));
            min_right = min(min_right, a[i] + (mid - timee[i]));
        }
        if(max_left <= min_right)
        {
            meet = mid;
            final_l = max_left;
            final_r = min_right;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << setprecision(20);
    cout << final_r;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> t;
    //t = 1;

    while(t--)
    {
        //ternary_search();
        bin_search();
        cout << endl;
    }
    return 0;
}

