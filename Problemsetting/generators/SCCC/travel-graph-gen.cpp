#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int m = opt<int>("m");
    int s = rnd.next(1, n);
    vector<int> p(n+1);
    for (int i = 1; i < n; i++){
        p[i] = rnd.next(i+1, n);
    }
    p[n] = rnd.next(1, n-1);

    vector<pair<int, int>> edges;
    vector<int> A;
    for (int i = 1; i <= n; i++) A.push_back(i);

    for (int i = 1; i < n; i++)
        if (i < p[i])
            edges.push_back(make_pair(i, p[i]));
        else
            edges.push_back(make_pair(p[i], i));

    for (int j = n-1; j < m; j++) {
        int i = rnd.next(1, n);
        if (i < p[i])
            edges.push_back(make_pair(i, p[i]));
        else
            edges.push_back(make_pair(p[i], i));
    }

    shuffle(edges.begin(), edges.end());
    shuffle(A.begin(), A.end());

    cout << n << ' ' << m << ' ' << s << endl;
    for (auto edge: edges)
        cout << (edge.first) << ' ' << (edge.second) << ' ' << rnd.next(1, 5000) << endl;
    for (int i = 0; i < n-1; i++) {cout << A[i] << ' ';}
    cout << A[n-1] << endl;
}