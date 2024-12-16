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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;

    vector<int> ones;
    // edge case: "11" => 1 because one 1 is enough, not 2.
    // so need to take account of this case at 2 ends 
    int count = 0;
    int is_either_end = false;

    s.push_back('0');

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (is_either_end) {
                ones.push_back(-count);
            } else {
                ones.push_back(count);
            }
            count = 0;
            is_either_end = false;
        } else {
            if (i == 0 || i == n - 1) is_either_end = true;
            count += 1;
        }
    }
    int min_time = INT_MAX;
    for (int count : ones) {
        if (count <= 2) {
            min_time = min(min_time, 0);
        }
        else if (count % 2 == 0) {
            min_time = min(min_time, count / 2 - 1);
        } else {
            min_time = min(min_time, count / 2);
        }
    }

    int res = 0;
    for (int count : ones) {
        res += count - min_time * 2;
    }
}