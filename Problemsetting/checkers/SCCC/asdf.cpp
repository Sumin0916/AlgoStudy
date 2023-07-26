#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;

int CCW(const Point &p1, const Point &p2, const Point &p3) {
    int res = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    res -= p2.x*p1.y + p3.x*p2.y + p1.x*p3.y;
    return (res>0) - (res<0);
}

bool Cross(Point a, Point b, Point c, Point d){
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if(ab==0 && cd == 0){
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return !(b <= c || d <= a || !(a==c && b==d));
    }
    return ab <= 0 && cd <= 0;
}

int main(){
    Point p1, p2, p3, p4;
    p1.x=1;p1.y=1;p2.x=79;p2.y=2;p3.x=1;p3.y=79;p4.x=2;p4.y=2;
    cout << Cross(p1, p2, p1, p3);
    return 0;
}