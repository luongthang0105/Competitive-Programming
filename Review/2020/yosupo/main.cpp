#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map<ll, ll> a;
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        ll t, k, l;
        cin >> t;
        if(t == 0)
        {
            cin >> k >> l;
            a[k] = l;
        }
        else
        {
            cin >> k;
            cout << a[k] << "\n";
        }
    }
    return 0;
}
