#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
stack<pii> SL, SR;

typedef long long ll;
const int maxN = 1e5 + 5;
ll a[maxN+1];
int n, k;

ll GCD(ll a, ll b)
{
    while (b > 0)
    {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Init()
{
    SL.push(pii(0, 0));
    SR.push(pii(0, 0));
    for (int i = 1; i <= k; ++i)
    {
        ll u = SL.top().second;
        u = GCD(u, a[i]);
        SL.push(pii(a[i], u));
    }
}
#define fi first
#define se second
void Solve()
{
    ll ans = SL.top().second;
    for (int i = k+1; i <= n; ++i)
    {

        ll u = SL.top().second;
        u = GCD(u, a[i]);
        SL.push(pii(a[i], u));

        if (SR.size() == 1)
        {
            while (SL.size() > 1)
            {
                ll u = SL.top().first;
                //cout << SL.top().fi << " " << SL.top().se <<endl;
                SL.pop();
                ll v = GCD(u, SR.top().second);
                //cout <<  u << " " << v << endl;
                SR.push(pii(u, v));
            }
        }
        SR.pop();
        ans = max(ans, GCD(SL.top().second, SR.top().second));
    }
    //cout<<ans;
}

int main()
{
    freopen("GCD.inp","r",stdin);
    freopen("GCD.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    Init();
    Solve();
    return 0;
}
