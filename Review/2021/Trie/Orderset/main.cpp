#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "main"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vii;
typedef unordered_map<ll, int> unomp;
typedef map<ll, int> mp;

const int maxn = 6e6 + 5e5;
int q, D = 31, pp = 1e9;

//const int maxn = 100;
//int q, D = 3, pp = 5;
int child[maxn][2], isEnd[maxn];
int dem[maxn][2];
int cnt = 0, num = 0;

bool check(int x)
{
    int node = 0;
    for(int i = D; i >= 0; --i){
        int c = (x >> i) & 1;
        if(child[node][c] == 0) return 0;
        node = child[node][c];
    }
    return isEnd[node];
}
void add(int x)
{
    int node = 0;
    for(int i = D; i >= 0; --i){
        int c = (x >> i) & 1;
        if(child[node][c] == 0) child[node][c] = ++cnt;
        dem[node][c]++;
        node = child[node][c];
    }
    isEnd[node] = 1;
}

void del(int x, int node, int bit)
{
    if(bit >= 0)
    {
        int c = (x >> bit) & 1;
        del(x, child[node][c], bit-1);
        if(dem[node][c] == 1)
            child[node][c] = 0;
        dem[node][c] -= 1;
    }
    else{
        isEnd[node] = 0;
    }
}

int kth_small(int k, int t)
{
    int node = 0, i = D;
    while(k > 0 && i >= 0)
    {
        if(k > dem[node][0])
        {
            k -= dem[node][0];
            t += (1 << i);
            node = child[node][1];
        }
        else
        {
            node = child[node][0];
        }
        i--;
    }
    return t;
}

int count_small(int x)
{
    int node = 0, k = 0;
    for(int i = D; i >= 0; --i)
    {
        int c = (x >> i) & 1;
        if(c == 1) k += dem[node][0];
        if(child[node][c] == 0) return k;
        node = child[node][c];
    }
    return k;
}
void inp()
{
    cin >> q;
    while(q--)
    {
        char c; int x;
        cin >> c >> x;
        if(c == 'I'){
            x += pp;
            if(!check(x))
                add(x), ++num;
        }
        else if(c == 'D')
        {
            x += pp;
            if(check(x))
                del(x, 0, D), --num;
        }
        else if(c == 'K')
        {
            if(x > num) {cout << "invalid" << endl; continue;}
            int t = 0;
            cout << kth_small(x, t) - pp << endl;
        }
        else if(c == 'C'){
            x += pp;
            cout << count_small(x) << endl;
        }
    }
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);
    inp();
    solve();
    return 0;
}
