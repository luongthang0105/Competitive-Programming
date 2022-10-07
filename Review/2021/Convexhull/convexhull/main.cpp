/// https://open.kattis.com/problems/convexhull
#include <bits/stdc++.h>
#define pb push_back
#define prob "main"
#define endl "\n"
using namespace std;

const int maxn = 1e4 + 5;

struct Points{
    int x, y;
};
Points A[maxn], B[maxn];
int n;

bool cmp(Points a, Points b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int cross(Points a, Points b, Points c){
    ///cross product of 2 vector ab and ac
    /// recall: a(xa, ya), b(xb,yb), c(xc, yc)
    /// vector: ab(xb - xa, yb - ya); ac (xc - xa, yc - ya)
    /// =>      ab(x1 , y1); ac(x2, y2)
    /// => S abc = 1/2 * |x1*y2 - x2*y1| => the expression in abs tells us the sign!
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
    ///negative => clockwise => upper
    ///positive => counter clockwise => lower
}

void print(vector<Points>& A)
{
    for(auto i : A) cout << i.x << " " << i.y << endl;
}
bool ss(Points A, Points B){
    if(A.x == B.x && A.y == B.y)
        return true;
    return false;
}
void cvhl(){
    vector<Points> Up(maxn), Down(maxn);
    int k = 0; ///spt cua mang Down / Up
    /// lower 1st
    for(int i = 0; i < n; ++i){
        while(k >= 2 && cross(Down[k-2], Down[k-1], A[i]) <= 0)
            /// check if cw => delete it
            --k;
        Down[k] = A[i];
        ++k;
    }
    Down.resize(k);

    //print(Down); cout << endl;

    k = 0;
    /// upper 2nd
    for(int i = 0; i < n; ++i){
        while(k >= 2 && cross(Up[k-2], Up[k-1], A[i]) >= 0)
            ///check if ccw => delete it
            --k;
        Up[k] = A[i];
        ++k;
    }
    Up.resize(k);
    //print(Up); cout << endl;

    for(int i = Up.size()-2; i > 0; --i)
    {
        if(ss(Up[i], Down.back()) == false)
            Down.pb(Up[i]);
    }
    cout << Down.size() << endl;
    print(Down);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(prob".inp", "r", stdin);freopen(prob".out", "w", stdout);

    while(true){
        cin >> n;
        if(n == 0) return 0;
        for(int i = 0; i < n ;++i){
            cin >> B[i].x >> B[i].y;
        }
        sort(B, B + n, &cmp);

        int newN = 0;
        A[newN++] = B[0];
        for(int i = 1; i < n; ++i)
        {
            A[newN++] = B[i];
            if(ss(B[i], B[i-1])) newN--;
        }
        n = newN;

        cvhl();
    }
    return 0;
}
