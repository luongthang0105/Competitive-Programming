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
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x] += 1;
    }

    priority_queue<pair<int ,int>> pq;
    for (auto m : cnt) {
        pq.push({m.second, m.first});
    }
    vector<vector<int>> ans;

    while (true) {
        vector<int> row;
        vector<pair<int, int>> used;
        bool outOfStuff = false;
        for (int i = 0; i < k; ++i) {
            if (pq.empty()) {
                outOfStuff = true;
                break;
            }
            pii top = pq.top();
            pq.pop();
            row.pb(top.second);
            if (top.first != 1) {
                top.first--;
                used.pb(top);
            }
        }
        if (outOfStuff) break;
        for (auto pi : used) {
            pq.push(pi);
        }
        ans.pb(row);
    }

    if (ans.size() == 0) {
        cout << "impossible";
        return 0;
    }
    for (auto v : ans) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
}