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

void update(int &x, int &y) {
    int minn = min(x, y);
    x -= minn;
    y -= minn;
}
void computeScissor(int &sA, int &pB, int &sB, int &rB, int &pointA, int &pointB) {
    if (pB != 0) {
        pointA += min(sA, pB);
        update(sA, pB);
    } else if (sB != 0) {
        update(sA, sB);
    } else if (rB != 0) {
        pointB += min(sA, rB);
        update(sA, rB);
    }
}

void computeRock(int &rA, int &pB, int &sB, int &rB, int &pointA, int &pointB) {
    if (sB != 0) {
        pointA += min(rA, sB);
        update(rA, sB);
    } else if (rB != 0) {
        update(rA, rB);
    } else if (pB != 0) {
        pointB += min(rA, pB);
        update(rA, pB);
    }
}

void computePaper(int &pA, int &pB, int &sB, int &rB, int &pointA, int &pointB) {
    if (rB != 0) {
        pointA += min(pA, rB);
        update(pA, rB);
    } else if (pB != 0) {
        update(pA, pB);
    } else if (sB != 0) {
        pointB += min(pA, sB);
        update(pA, sB);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    int n;
    cin >> n;

    int rA = 0, rB = 0, sA = 0, sB = 0, pA = 0, pB = 0;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (c == 'R') rA += 1;
        else if (c == 'P') pA += 1;
        else sA += 1;
    }

    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (c == 'R') rB += 1;
        else if (c == 'P') pB += 1;
        else sB += 1;
    }    
    int pointA = 0, pointB = 0;
    int index = 0;
    while (sA != 0 || rA != 0 || pA != 0) {
        // index++;
        // if (index == 10) break;
        // cout << sA << " " << pA <<  " " << rA << endl;
        if (sA != 0) {
            computeScissor(sA, pB, sB, rB, pointA, pointB);
        }
        if (rA != 0) {
            computeRock(rA, pB, sB, rB, pointA, pointB);
        }
        if (pA != 0) {
            computePaper(pA, pB, sB, rB, pointA, pointB);
        }
    }

    cout << pointA - pointB;
}