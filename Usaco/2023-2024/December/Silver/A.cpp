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
map<int, ll> segments;

void print_segment() {
    cout << "-----------Segments-----------" << endl;
    for (auto segment: segments) {
        cout << "Segment with w=" << segment.first;
        cout << "; count=" << segment.second;
        cout << endl;
    }    
    cout << "------------------------------" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pll> cnt; 
    for (int i = 0; i < n; ++i) {
        ll w, c;
        cin >> w >> c;
        cnt.push_back({w, c});
    }

    sort(cnt.begin(), cnt.end());
    ll ans = 0;
    segments[INT_MIN] = m;

    for (auto p : cnt) {
        ll weight = p.first;
        ll org_cows = p.second;
        ll cows = p.second;
        // cout << "Weight = " << weight << endl;
        for (auto it = segments.begin(); it != segments.end();) {
            auto [tower_weight, segment_len] = *it;
            if (weight - tower_weight >= k) {
                if (cows >= segment_len) {
                    segments.erase(it);
                    segments[weight] += segment_len;
                    cows -= segment_len;
                    it = segments.begin();
                } else {
                    it->second -= cows;
                    segments[weight] += cows; 
                    cows = 0;
                    break;
                }
            } else {
                break;
            }
        }
        // print_segment();

        ans += org_cows - cows;
    }
    cout << ans;
    
}
// for (int i = 0; i < m; ++i) {
//     ll prev = -1e9-1;
    
//     for (int j = 0; j < cnt.size(); ++j) {
//         auto pair = cnt[j];
//         ll weight = pair.first;
//         ll cows = pair.second;
//         if (weight - prev >= k && cows > 0) {
//             ans += 1;
//             cnt[j].second -= 1;
//             prev = weight;    
//         }
//     }
// }