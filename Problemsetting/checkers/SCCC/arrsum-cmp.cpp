#include "testlib.h"
#include<bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;
using ll = long long;

constexpr ll MAX = 1'000'000'000'000'000'000;
constexpr ll MIN = -1'000'000'000'000'000'000;
int N;
vector<int> R;
string S;

void check(InStream &in) {
    string NS = in.readWord();
    if (S == "NO" && NS == "YES") in.quitf(_wa, "ANS != OUF");
    S = NS;
    if (S.compare("NO") == 0) return;
    if (S != "YES") in.quitf(_wa, "no matching 'YES' or 'NO' S = %s",S.c_str());
    vector<ll> A = in.readLongs(N, MIN, MAX, "A");
    vector<ll> B = in.readLongs(N, MIN, MAX, "B");
    for (int i = 0; i < N; i++) if (A[i] + B[i] != R[i]) in.quitf(_wa, "A+B != R");
    return;
}

int main(int argc, char* argv[]) {
    setName("Test Checker");
    registerTestlibCmd(argc, argv);

    N = inf.readInt(1, 100'000, "N");
    R = inf.readInts(N, -1'000'000'000, 1'000'000'000, "R");
    check(ans);
    check(ouf);
    quitf(_ok, "");
}