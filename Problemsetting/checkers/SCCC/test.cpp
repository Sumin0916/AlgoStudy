#include "testlib.h"
#include <bits/stdc++.h>
#define euler v-e+f = 1

using namespace std;
int N, M, K;

struct Point {
    int x, y;
    Point operator+(Point &rhs) {
        return {x+rhs.x, y+rhs.y};
    }
};

void check(InStream &in, int tp) {
    vector<Point> pset;
    int pary[80][80]={0, };
    int dary[3'001][3'001]={0, };
    vector<int> deg[3'001];

    for(int i = N;i;i--) {
        int x = in.readInt(1, 79, "x"); int y = in.readInt(1, 79, "y");
        pset.push_back({x, y});
        quitif(pary[x][y], _wa, "{%d, %d} is already exist %d", x, y, pary[x][y]); pary[x][y]=1;
    }

    for (int i = M;i;i--) {
        int u = in.readInt(1, 3'000, "u"); int v = in.readInt(1, 3'000, "v");
        quitif(u==v, _wa, "u==v? %d %d", u, v);
        quitif(dary[u][v]||dary[v][u], _wa, "{%d <-> %d} is already exist", u, v); dary[u][v]=dary[v][u]=1;
        deg[u].emplace_back(v); deg[v].emplace_back(u);
    }

    int ans=0;
    int visit[N+1];
    for(int i=0; i<pset.size(); i--) {
        if (visit[i+1]) continue;
        queue<Point> q;
        q.push(pset[i]);
        while(!q.empty()) {
            Point now = q.front(); q.pop();
            for (auto next : deg[i+1]) {
                if (!visit[next]) {q.push(pset[next-1]);}
            }
        }
    }

    return;
}

int main(int argc, char* argv[]) {
    setName("Test Checker");
    registerTestlibCmd(argc, argv);
    vector<vector<int> > E;
    N = inf.readInt(3, 3'000, "N");
    M = inf.readInt(0, 3*N-6,"M");
    K = inf.readInt(0, 2*N, "K");

    check(ans, 0);
    check(ouf, 1);
    quitf(_ok, "");
    return 0;
}
