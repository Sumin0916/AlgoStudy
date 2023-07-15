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
    A[0] = rnd.next(1, 10);
    for(int i = 1; i < N; i++) {
        if (rnd.next() > 0.2) {
            if (A[i-1] > 3) rnd.next() > 0.5? A[i]=rnd.next(1, A[i-1]-3) : A[i]=rnd.next(A[i-1]-3, 10);
            else A[i] = rnd.next(A[i-1]+3, 10);
        }
        else A[i] = rnd.next(1, 10);
    }
    for (int i=0; i<N-1;i++) cout << A[i] << ' ';
    cout << A[N-1] << endl;
}
