#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int n;
int res;
vector<p> arr;
int ccw(p p1, p p2, p p3) {
    ll res = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    return (res > 0) - (res < 0);
}

ll Dist(p p1, p p2) {
    ll dx = p2.x-p1.x; ll dy = p2.y-p1.y;
    return dx*dx + dy*dy;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<p> res;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    swap(arr[0], *min_element(arr.begin(), arr.end()));
    sort(arr.begin()+1, arr.end(), [&](auto a, auto b) {
        int dir = ccw(arr[0], a, b);
        if (dir != 0) return dir > 0;
        return Dist(arr[0], a) < Dist(arr[0], b); } );
    for (auto i : arr) {
        while(res.size() >= 2 && ccw(res[res.size()-2], res.back(), i) <= 0) res.pop_back();
        res.push_back(i);
    }
    cout << res.size();
}