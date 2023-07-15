#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> prufer_to_tree(int n, vector<int> &a) {
    vector<pair<int, int>> res;
    vector<int> deg(n+1);
    priority_queue<int> L;

    for(auto i : a) deg[i]++;
    for(int i=n; i; i--) if(!deg[i]) L.emplace(i);
    for(auto i : a) {
        res.emplace_back(i, L.top());L.pop();
        if(!--deg[i]) L.push(i);
    }
    int u = L.top();L.pop(); int v = L.top();L.pop();
    res.emplace_back(u, v); return res;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int NMAX = opt<int>("NMAX");
    int NMIN = opt<int>("NMIN");
    vector<int> A;
    int N = rnd.next(NMIN, NMAX);
    for(int i = N-2; i; i--) {A.push_back(rnd.next(1, N));}
    vector<pair<int, int>> R = prufer_to_tree(N, A);
    cout << N << endl;
    for(auto i : R) cout << i.first << ' ' << i.second << endl;
}