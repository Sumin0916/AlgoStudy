#include<bits/stdc++.h>
using namespace std;

int uf[2020];
int n, m, s, res;
int arr[2020];
vector<tuple<int, int, int>> edge;

void init() {
    for (int i = 0; i < n; i++) uf[i] = i;
}

int find(int a) {
    if (uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int u, int v) {
    u = find(u); v = find(v);
    if (u==v) return false;
    if (uf[u] > uf[v]) swap(u, v);
    uf[v] = u;
    return true;
}

int main() {
    cin >> n >> m >> s;
    init();
    for (int i = 0; i < m; i++) {
        int u, e, w;
        cin >> u >> e >> w;
        edge.push_back(make_tuple(u, e, w));
    }
    sort(edge.begin(), edge.end(), [](auto a, auto b){ return get<2>(a) < get<2>(b); });
    int cnt = 0;
    for (auto &p : edge) {
        int u, e, w;
        u = get<0>(p); e= get<1>(p); w = get<2>(p);
        if (merge(u, e)) {
            res += w;
            if (++cnt == n-1) break;
        }
    }
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << res;
}