#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(2, 300, "N");
    int C[N+1][N+1] = {0, };
    vector<int> E[N+1];
    inf.readEoln();
    for (int i=N-1;i;i--) {
        int u = inf.readInt(1, N, "U"); inf.readSpace();
        int v = inf.readInt(1, N, "V"); inf.readEoln();
        ensuref(!C[u][v], "Repeted edges...");
        C[u][v] = C[v][u] = 1;
        E[u].push_back(v);E[v].push_back(u);
    }
    queue<int> Q;
    bool VI[N+1] = {false, };
    Q.push(1);
    VI[0] = true;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto i : E[now]) {
            if (!VI[i]) {
                Q.push(i);
                VI[i] = true;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) ensuref(VI[i], "tree must connected \ node num  = %d", i);
    inf.readEof();
    return 0;
}