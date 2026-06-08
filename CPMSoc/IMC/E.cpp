#define _USE_MATH_DEFINES

#include <cstring>
#include <climits>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;

const long long MOD = 1e9 + 7;

const long long maxn = 5e6 + 5;
const long long maxx = 2e3 + 5;

long long n, m, k;

long long a[maxn], b[maxn];
// long long f[maxx][maxx], g[maxx][maxx];

// vector<long long> g[100005];

double v[4] = {1, 0, -1, 0};
double h[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x, y, z, t;
    x = 0;
    y = 0;
    cin >> z >> t >> n;

    for (int i = 1; i <= n; i++)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double tam_x = (x2 + x1) / 2;
        double tam_y = (y2 + y1) / 2;

        double r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            double next_x = tam_x + r * v[i];
            double next_y = tam_y + r * h[i];
            if (i == 0)
            {
                if (next_x >= z)
                {
                    flag = false;
                }
            }
            else if (i == 1)
            {
                if (next_y >= t)
                {
                    flag = false;
                }
            }
            else if (i == 2)
            {
                if (next_x <= x)
                {
                    flag = false;
                }
            }
            else
            {
                if (next_y <= y)
                {
                    flag = false;
                }
            }
        }
        if (flag == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}