#include "testlib.h"
#include<bits/stdc++.h>
 
using namespace std;

int CK[2] = {0, };
int CE[301][301] = {0, };

int N;

pair<int, int> longest_node(int start, vector<vector<int>> &E) {
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
    pair<int, int> R;
    R.first = MN; R.second = MW;
    return R;
}

int tree_len(vector<vector<int>> &E) {
    return longest_node(longest_node(1, E).first, E).second;
}

void check(InStream &in, int tp, vector<vector<int>> E) {
    int K = in.readInt(0, N-1, "K");
    int R = in.readInt(1, N-1, "R");
    int CA[301][301] = {0, };
    for (int i = 0; i < 301; i++) {for (int j = 0; j < 301; j++) {CA[i][j] = CE[i][j];}}

    if (2 * (N-1) < N * (N-1) / 2) in.quitif(R != 2, _wa, "");
    else in.quitif(R != 1, _wa, "");

    for(int i=K;i;i--) {
        int U = in.readInt(1, N, "U"); int V = in.readInt(1, N, "V");
        in.quitif(CA[U][V] || CA[V][U], _wa, "repeated edge U->V %d U<-V %d TP : %d",CA[U][V], CA[V][U], tp); in.quitif((U == V), _wa, "U==V %d %d", U, V);
        CA[U][V] = CA[V][U] = 1;
        E[U].emplace_back(V); E[V].emplace_back(U);
    }
    int TL;
    
    in.quitif(R != tree_len(E), _wa, "R is not ans | tp: %d you:%d != ans:%d",tp, R, tree_len(E));
    CK[tp] = 1;
    return;
}

int main(int argc, char* argv[]) {
    setName("Test Checker");
    registerTestlibCmd(argc, argv);
    vector<vector<int> > E;
    N = inf.readInt(2, 300, "N");
    E.resize(N+1);
    
    for(int i=N-1;i;i--) {
        int U = inf.readInt(1, N, "U"); int V = inf.readInt(1, N, "V");
        inf.quitif(CE[U][V] || CE[V][U], _wa, "repeated edge U->V %d U<-V %d",CE[U][V], CE[V][U]);
        inf.quitif((U == V), _wa, "U==V %d %d", U, V);
        CE[U][V] = CE[V][U] = 1;
        E[U].emplace_back(V); E[V].emplace_back(U);
    }

    check(ans, 0, E);
    check(ouf, 1, E);
    ouf.quitif(!CK[0] || !CK[1], _wa, "ANS != OUF");
    quitf(_ok, "");
    return 0;
}
