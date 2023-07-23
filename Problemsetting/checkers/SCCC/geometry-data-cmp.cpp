#include "testlib.h"
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;
int N, M, K;

int CCW(const Point &p1, const Point &p2, const Point &p3) {
    int res = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    res -= p2.x*p1.y + p3.x*p2.y + p1.x*p3.y;
    return (res>0) - (res<0);
}

bool Cross(Point a, Point b, Point c, Point d){
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if(ab==0 && cd == 0){
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return !(b <= c || d <= a || ((a==c) && (b!=d)) || ((a!=c) && (b==d)));
    }
    return ab <= 0 && cd <= 0;
}

void check(InStream &in) {
    vector<Point> pset;
    int pary[80][80]={0, };
    int dary[3'001][3'001]={0, };
    vector<Point> edges;

    for(int i = N;i;i--) {
        int u = in.readInt(1, 79, "u"); int v = in.readInt(1, 79, "v");
        pset.emplace_back(u, v);
        in.quitif(pary[u][v], _wa, "{%d, %d} is already exist %d", u, v, pary[u][v]); pary[u][v]=1;
    }

    for (int i = M;i;i--) {
        int u = in.readInt(1, 3'000, "u"); int v = in.readInt(1, 3'000, "v");
        in.quitif(u==v, _wa, "u==v? %d %d", u, v);
        in.quitif(dary[u][v]||dary[v][u], _wa, "{%d <-> %d} is already exist", u, v); dary[u][v]=dary[v][u]=1;
        edges.emplace_back(u, v);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(dary[i][j]&&dary[j][i]) {
                dary[i][j]=dary[j][i]=0;
                Point p1, p2, p3, p4;
                p1 = pset[edges[i-1].x-1]; p2 = pset[edges[i-1].y-1]; p3 = pset[edges[j-1].x-1]; p4 = pset[edges[j-1].y-1];
                in.quitif(Cross(p1, p2, p3, p4), _wa, "%d-%d X %d-%d",edges[i-1].x, edges[i-1].y, edges[j-1].x, edges[j-1].y);
            }
        }
    }
    return;
}

int main(int argc, char* argv[]) {
    setName("Test Checker");
    registerTestlibCmd(argc, argv);

    N = inf.readInt(3, 3'000, "N");
    M = inf.readInt(0, 3*N-6,"M");
    K = inf.readInt(0, 2*N, "K");

    check(ans);
    check(ouf);
    quitf(_ok, "");
    return 0;
}
