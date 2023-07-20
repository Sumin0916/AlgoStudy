#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
int A[1'000'001];

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int NMAX = opt<int>("NMAX");
    int NMIN = opt<int>("NMIN");
    int N = rnd.next(NMIN, NMAX);
    cout << N << endl;
    for(int i = 0; i < N; i++) {
        A[i] = rnd.next(1, 10);
    }
    for (int i=0; i<N-1;i++) cout << A[i] << ' ';
    cout << A[N-1] << endl;
}
