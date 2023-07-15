#include "testlib.h"
#include <vector>
#include <queue>

using namespace std;

int CK[2] = {0, };
int N;
int CE[301][301] = {0, };
vector<vector<int> > E;

vector<int, int> longest_node(int start) {
    int MN = 1, MW = 0;
    queue<pair<int, int>> Q;
    Q.emplace(start, 0);
    int V[N+1] = {false, };
    V[start] = true;
    while(!Q.empty()) {
        int now = Q.front().first; int w = Q.front().second;
        if(w > MW){ MN=now;MW=w; }
        Q.pop();
        for(auto i : E[now]) {
            if(!V[i]) {
                V[i] = true;
                Q.emplace(i, w+1);
            }
        }
    }
    vector<int, int> R;
    R.push_back(MN); R.push_back(MW);
    return R;
}

int tree_len(void) {
    return longest_node(longest_node(1)[0])[1];
}

void check(InStream &in, int tp) {
    int K = in.readInt(0, N-1);
    int R = in.readInt(1, N-1);
    if (2 * (N-1) < N * (N-1) / 2) quitif(R != 2, _wa, "");
    else quitif(R != 1, _wa, "");

    for(int i=K;i;i--) {
        int U = in.readInt(1, N); int V = in.readInt(1, N);
        quitif(CE[U][V] || CE[V][U] || (U == V), _wa, "repeated edge or U==V");
        CE[U][V] = CE[V][U] = 1;
        E[U].emplace_back(V, 0); E[V].emplace_back(U, 0);
    }
    quitif(R != tree_len(), _wa, "R is not ans");
    CK[tp] = 1;
    return;
}

int main(int argc, char* argv[]) {
    setName("Test Checker");
    registerTestlibCmd(argc, argv);

    N = inf.readInt(2, 300, "N");
    E.resize(N+1);
    check(ans, 0);
    check(ouf, 1);
    ouf.quitif(!CK[0] || !CK[1], _wa, "ANS != OUF");
    quitf(_ok, "");
}