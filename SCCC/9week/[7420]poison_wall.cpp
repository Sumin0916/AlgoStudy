#include<bits/stdc++.h>
#define x first 
#define y second

using namespace std;
using p = pair<int, int>;
using ll = long long int;

int N, L;
vector<p> points;
ll res;

int ccw(p &p1, p &p2, p &p3) {
    ll res = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    return (res > 0) - (res < 0);
}

ll dist(p &p1, p &p2) {
    ll dx = p1.x - p2.x; ll dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin()+1, points.end(), [&](auto a, auto b){
        ll d = ccw(points[0], a, b);
        if (d != 0) return d > 0;
        return a.y > b.y;
    });
    vector<p> r;
    for (auto i : points) {
        while (r.size() >= 2 && ccw(r[r.size()-2], r.back(), i) <= 0) r.pop_back();
        r.push_back(i);
    }
    for (auto i : r) cout << i.x << ' ' << i.y << '\n';
}