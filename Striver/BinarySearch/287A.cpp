// Problem link: https://codeforces.com/contest/287/problem/B
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

ll n, k;
ll sum;
bool test(ll cand) {
    ll sumToCand = ((k - cand) + 1) * (k - cand) / 2;
    // cout << cand << " " << sumToCand << endl;
    return (sum - sumToCand >= n);
} 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    cin >> n >> k;
    
    n--;
    k--;
    sum = k * (k + 1) / 2;
    if (n > sum) {
        cout << -1;
        return 0;
    } 

    ll low = 0, high = k;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (test(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}