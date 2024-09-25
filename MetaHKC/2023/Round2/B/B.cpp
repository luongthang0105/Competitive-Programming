// Problem link: 
#include <bits/stdc++.h>
#define inf 1000000007
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define prob "B" 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;

const int maxn = 1e5 + 5;

enum cmp_type {
    L,
    H,
    E
};

class Point {
public:
    cmp_type type;
    int a;
    int b;

    Point(int a, int b) {
        this->a = a;
        this->b = b;
        if (this->a < this->b) this->type = L;
        else if (this->a == this->b) this->type = E;
        else this->type = H;
    }
    void invert() {
        swap(a, b);
        if (type == L) type = H;
        else if (type == H) type = L;
    }

    bool is_invert_of(Point other) {
        return this->a == other.b && this->b == other.a;
    }

    void display() {
        cout << "Point: " << "a=" << a;
        cout << " b=" << b;
        cout << " type=" << type << endl;
    }
};

void printAns(int index, int ans) {
    cout << "Case #" << index << ": " << ans;
    cout << endl;
}

bool is_valid(deque<Point> points) {
    // check L H
    int i = 0;
    for (; i < points.size() / 2; ++i) {
        if (points[i].type == H) return false;
    }

    if (points.size() % 2 == 1) i += 1;
    for (; i < points.size(); ++i) {
        if (points[i].type == L) return false;
    }

    // check reverse
    for (int j = 0; j < points.size() / 2; ++j) {
        if (!points[j].is_invert_of(points[points.size() - 1 - j])) return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        deque<Point> points;
        int same_points_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) same_points_cnt++;
            points.push_back(Point(a[i], b[i]));
            // points[i].display();
        }

        if ((n % 2 == 0 && same_points_cnt > 0) || (n % 2 == 1 && same_points_cnt != 1)) {
            printAns(k, -1);
            continue;
        }

        int inv_point = n - 1;
        int inv_count = 0;
        bool inv_ok = true;
        for (int i = 0; i < n; ++i) {
            Point point = points[i];
            if (n % 2 == 1) {
                if (point.type == E) inv_point = i;
                if (i < n - 1 && point.type != points[i + 1].type) {
                    if ((points[i + 1].type != E) && (point.type != E)) {
                        inv_ok = false;
                        break;
                    } 
                }
            } else {
                if (i < n - 1 && point.type != points[i + 1].type) {
                    inv_count += 1;
                    inv_point = i;
                }
            }
        }

        if (!inv_ok) {
            printAns(k, -1);
            continue;
        }
        if (n % 2 == 0 && inv_count > 1) {
            printAns(k, -1);
            continue;
        }

        int key_point = (n % 2 == 0) ? n/2-1 : n / 2;
        // cout << "key point:" << key_point << endl;
        // cout << "inv point:" << inv_point << endl;
        int ans = -1;
        for (int j = 0; j < 2 * n; ++j) {
            if (inv_point == key_point) {
                if (is_valid(points)) {
                    ans = j;
                    break;
                }
            }
            points[0].invert();
            points.push_back(points[0]);
            points.pop_front();

            inv_point -= 1;
            if (inv_point < 0) inv_point = n - 1;
        }
        printAns(k, ans);
    }
}