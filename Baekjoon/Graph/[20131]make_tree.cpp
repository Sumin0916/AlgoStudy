#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> prufer_to_tree(int n, vector<int> &a) {
    vector<pair<int, int>> res;
    vector<int> deg(n+1);
    priority_queue<int> L;

    for(auto i : a) deg[i]++;
    for(int i=n; i; i--) if(!deg[i]) L.emplace(i);
    for(auto i : a) {
        (i < L.top()) ? res.emplace_back(i, L.top()) : res.emplace_back(L.top(), i);
        L.pop();
        if(!--deg[i]) L.push(i);
    }
    int u = L.top();L.pop(); int v = L.top();L.pop();
    (u < v) ? res.emplace_back(u, v) : res.emplace_back(v, u);
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> a;
    for (int i=N-2;i;i--) {int b; cin >> b; a.push_back(b);}
    vector<pair<int, int>> res;
    res = prufer_to_tree(N, a);
    sort(res.begin(), res.end());
    for (auto i: res) cout << i.first << ' ' << i.second << '\n';
    return 0;
}