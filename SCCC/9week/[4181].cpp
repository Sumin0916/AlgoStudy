#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int n;
int res;
vector<p> arr;

int ccw(p &p1, p &p2, p &p3) {
    ll res = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    return (res > 0) - (res < 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<p> res;
    vector<p> temp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; char s;cin >> a >> b >> s;
        if (s == 'N') continue;
        arr.push_back(make_pair(a, b));
    }

    swap(arr[0], *min_element(arr.begin(), arr.end()));

    sort(arr.begin()+1, arr.end(), [&](auto a, auto b) {
        ll dir = ccw(arr[0], a, b);
        if (dir != 0) return dir > 0;
        if (a.x != b.x) return (a.x < b.x);
        return (a.y < b.y);

    });

    for (vector<p>::iterator i = arr.begin(); i != arr.end(); i++) {
        while (res.size() >= 2 && ccw(res[res.size()-2], res.back(), *i) < 0) {
            temp.push_back(res.back());
            res.pop_back();
        }
        res.push_back(*i);
    }
    for (vector<p>::reverse_iterator i = temp.rbegin(); i != temp.rend(); i++) res.push_back(*i);

    cout << res.size() << '\n';
    for (auto a : res) cout << a.x << ' ' << a.y << '\n';
}