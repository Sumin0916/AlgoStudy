#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 2'000, "N");
    inf.readSpace();
    int M = inf.readInt(N-1, 5'000, "M");
    inf.readSpace();
    int S = inf.readInt(1, N, "S");
    inf.readEoln();
    for (int i = 0; i < M; i++) {
        int u = inf.readInt(1, N);
        inf.readSpace();
        int v = inf.readInt(u, N);
        inf.readSpace();
        inf.readInt(1, 5'000);
        inf.readEoln();
    }
    int V[N+1] = {0, };
    vector<int> A = inf.readInts(N, 1, N, "A");
    for (auto i: A) {
        ensuref(!(V[i] == 1), "A = {x | 1 <= x <= n} i = %d V[i] = %d", i, V[i]);
        V[i] = 1;
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}