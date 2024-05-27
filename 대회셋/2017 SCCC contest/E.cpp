#include <bits/stdc++.h>

using namespace std;

struct game{
    int i;
    long long int cost;
    long long int h;
    game(int a, int b, int c) : i(a), cost(b), h(c) {
    }
    bool operator <(game ot) {
        long long int x = ot.cost * h;
        long long int y = cost * ot.h;
        if(x == y) {
            if(cost == ot.cost) {
                return i < ot.i;
            }
            return cost < ot.cost;
        }
        return x > y;
    }
};

vector<game> a;
int main(void) {
    int n, k, x, y,z;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        a.push_back(game(x, y, z));
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < k; i++) {
        cout <<a[i].i << "\n";
    }
    return 0;
}