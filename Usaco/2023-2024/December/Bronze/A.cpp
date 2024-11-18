// Problem link: https://www.acmicpc.net/problem/31063
// Intuition behind this is that the first cow will **almost** always double it size.
// This is because if it encounter a taller candy, it will eat that candy up to it size
// => So it doubles it size. Note that if it doubles it self 30 times, its height gets to at 
// least 2^30 which is GREATER than the bound of candy height (ie. 10^9).
// On the other hand, if it encounters a smaller candy, it will just yoink the whole thing
// and everybody after that will not have anything to do.

// So for the worst case time complexity is when it always encounters a candy of taller height.
// This is because the other cow will have a chance to yoink parts of the candy, which may take O(n) at worst.
// And since we can only do this up to 30 times (~ log2(10^9)), the time complexity would be O(log2(10^9) * N).
// But dont forget that we need O(M) to read the inputs, so it would be O(M + log2(10^9) * N)

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
vector<ll> heights;
vector<ll> candies;
vector<ll> candies_sum;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        heights.pb(x);
    }

    for (int i = 0; i < m; ++i) {
        ll candy_height; cin >> candy_height;
        ll bottom = 0LL;
        for (int j = 0; j < n; ++j) {
            if (heights[j] > bottom) {
                ll eat_up_to = min(heights[j], candy_height);
                heights[j] += eat_up_to - bottom;
                bottom = eat_up_to;
            }
            if (candy_height <= bottom) break;
        }
    }
    for (ll height : heights) {
        cout << height << '\n';
    }
}