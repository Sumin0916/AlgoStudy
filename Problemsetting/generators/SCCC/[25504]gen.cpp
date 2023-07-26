#include "testlib.h"
#include <bits/stdc++.h>
#define sp ' '
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int NMAX = opt<int>("NMAX");
    int NMIN = opt<int>("NMIN");
    int MMAX = opt<int>("MMAX");
    int MMIN = opt<int>("MMIN");
    int QMAX = opt<int>("QMAX");
    int QMIN = opt<int>("QMIN");

    vector<int> A;

    int N = rnd.next(NMIN, NMAX);
    int M = rnd.next(MMIN, MMAX);
    int Q = rnd.next(QMIN, QMAX);

    cout << N << sp << M << sp << Q << endl;

    for(int i=M;i;i--){
        int t = rnd.next(1, 50'000);
        int u = rnd.next(1, N); int v = rnd.next(u+1, N);
        if(rnd.next()>0.5) swap(u, v);
        cout << u << sp << v << sp << t << endl;
    }

    for(int i=Q;i;i--){
        int u = rnd.next(1, N); int v = rnd.next(u+1, N);
        if(rnd.next()>0.5) swap(u, v);
        cout << u << sp << v << endl;
    }
    return 0;
}