#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    const int MAX = 1'000'000'000;
    const int MIN = -1'000'000'000;
    registerValidation(argc, argv);

    int N = inf.readInt(1, 100'000, "N");
    inf.readEoln();
    inf.readInts(N, MIN, MAX, "arr");
    inf.readEoln();
    inf.readEof();
    return 0;
}