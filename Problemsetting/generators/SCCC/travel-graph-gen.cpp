#include "testlib.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int m = opt<int>("m");
    int s = rnd.next(n) + 1;
    vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, n);

    vector<int> perm = rnd.perm(n);

    vector<pair<int, int>> edges;
    vector<int> A;
    for (int i = 1; i <= n; i++) A.push_back(i);

    for (int i = 1; i < n; i++)
        if (perm[i] < perm[p[i]])
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else if (perm[i] > perm[p[i]])
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    for (int j = n-1; j < m; j++) {
        int i = rnd.next(n);
        if (perm[i] < perm[p[i]])
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else if (perm[i] > perm[p[i]])
            edges.push_back(make_pair(perm[p[i]], perm[i]));
    }

    shuffle(edges.begin(), edges.end());
    shuffle(A.begin(), A.end());

    cout << n << ' ' << m << ' ' << s << endl;
    for (auto edge: edges)
        cout << (edge.first + 1) << ' ' << (edge.second + 1) << ' ' << rnd.next(1, 5000) << endl;
    for (int i = 0; i < n-1; i++) {cout << A[i] << ' ';}
    cout << A[n-1] << endl;
}