// Problem link:
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "wormsort"
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

class UnionFind
{
private:
    int n_;
    vector<int> parents_;
    vector<int> sizes_;

public:
    UnionFind(int n) : n_{n}
    {
        parents_.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parents_[i] = i;
        };
        sizes_.resize(n + 1, 1);
    }

    int findRoot(int u)
    {
        return u == parents_[u] ? u : (parents_[u] = findRoot(parents_[u]));
    }

    void merge(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return;
        if (sizes_[u] > sizes_[v])
            swap(u, v);

        // merge to v, since v is bigger
        parents_[u] = v;
        sizes_[v] += sizes_[u];
    }
};

int n, m;
vector<pair<int, int>> necessaryEdges;

using WormHole = tuple<int, int, int>;
vector<WormHole> wormHoles;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(prob ".in", "r", stdin);
    // freopen(prob ".out", "w", stdout);

    cin >> n >> m;
    vector<int> cowPosMap(n + 1);
    vector<int> cowPosLinear(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        cowPosMap[x] = i;
        cowPosLinear[i] = x;
    }

    for (int i = 1; i <= m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        wormHoles.push_back({x, y, w});
    }

    sort(wormHoles.begin(), wormHoles.end(), [](const WormHole &a, const WormHole &b)
         { return get<2>(a) > get<2>(b); });

    for (int i = n; i >= 1; --i)
    {
        int ithCowPos = cowPosMap[i];
        if (ithCowPos == i)
            continue;

        necessaryEdges.push_back({ithCowPos, i});

        int cowAtCurrPos = cowPosLinear[i];
        cowPosMap[cowAtCurrPos] = ithCowPos;
    }

    if (necessaryEdges.size() == 0)
    {
        cout << -1;
        return 0;
    }

    UnionFind uf{n};
    int currCompletedNecEdge = 0;
    for (const auto &[x, y, w] : wormHoles)
    {
        uf.merge(x, y);

        while (currCompletedNecEdge < necessaryEdges.size() &&
               uf.findRoot(necessaryEdges[currCompletedNecEdge].first) ==
                   uf.findRoot(necessaryEdges[currCompletedNecEdge].second))
        {
            currCompletedNecEdge++;
        }

        if (currCompletedNecEdge == necessaryEdges.size())
        {
            cout << w;
            return 0;
        }
    }

    return 0;
}