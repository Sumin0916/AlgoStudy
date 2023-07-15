#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;
int N;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    N = inf.readInt(2, 2'000, "N");
    vector<int> E[N+1];
    inf.readSpace();
    int M = inf.readInt(N-1, 5'000, "M");
    inf.readSpace();
    int S = inf.readInt(1, N, "S");
    inf.readEoln();
    for (int i = 0; i < M; i++) {
        int u = inf.readInt(1, N);
        inf.readSpace();
        int v = inf.readInt(u+1, N);
        ensuref((u < v), "u:%d >= v:%d", u, v);
        E[u].push_back(v);
        E[v].push_back(u);
        inf.readSpace();
        inf.readInt(1, 5'000);
        inf.readEoln();
    }
    
    queue<int> Q;
    bool VI[N+1];
    for (int i = 1; i <= N; i++) {VI[i] = false;}
    Q.push(1);
    VI[0] = true;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto i = E[now].begin(); i < E[now].end(); i++) {
            if (!VI[*i]) {
                Q.push(*i);
                VI[*i] = true;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) ensuref(VI[i], "graph must connected i  = %d", i);
    int V[N+1] = {0, };
    vector<int> A = inf.readInts(N, 1, N, "A");
    for (auto i: A) {
        ensuref(V[i] == 0, "A = {x | 1 <= x <= n} i = %d V[i] = %d", i, V[i]);
        V[i] = 1;
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}