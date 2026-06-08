#include <bits/stdc++.h>
using namespace std;

int main()
{
    double w_room, h_room;
    cin >> w_room >> h_room;
    int n;
    cin >> n;

    // double ans = (double)(w_room * h_room) / 1000;
    double ans = (w_room) * (h_room);
    while (n--)
    {
        double w_window, h_window;
        cin >> w_window >> h_window;
        double buf = (w_window) * (h_window);
        ans -= buf;
        if (ans <= 0)
        {
            cout << "Please check the dimensions.\n";
            return 0;
        }
    }

    cout << "The Net Wall Panel Area is " << fixed << setprecision(2) << ans / 1000000.0 << " square metres.\n";
}