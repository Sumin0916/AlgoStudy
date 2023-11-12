#include "testlib.h"
#include "path-query.h"
#include <bits/stdc++.h>
#define sp ' '
using namespace std;

int N;

vector<pair<int, int>> prufer_to_tree(int n, vector<int> &a) {
    vector<pair<int, int>> res;
    vector<int> deg(n+1);
    priority_queue<int> L;

    for(auto i : a) deg[i]++;
    for(int i=n; i; i--) if(!deg[i]) L.emplace(i);
    for(auto i : a) {
        res.emplace_back(i, L.top());L.pop();
        if(!--deg[i]) L.push(i);
    }
    int u = L.top();L.pop(); int v = L.top();L.pop();
    res.emplace_back(u, v); return res;
}

vector<pair<int, int>> extend_edge(int S, int E, int N) {
    vector<pair<int, int>> R;
    if(N==2){R.emplace_back(S, E);return R;}
    vector<int> nodes;
    for(int i=1;i<=N;i++) {if(i==S || i==E)continue;nodes.emplace_back(i);}
    shuffle(nodes.begin(), nodes.end());
    if (N>=4){
        if(rnd.next()>0.5){R.emplace_back(S, nodes[0]);R.emplace_back(nodes[0], E);}
        else{R.emplace_back(S, nodes[0]);R.emplace_back(nodes[0], nodes[1]);R.emplace_back(nodes[1], E);}
    }
    else if (N==3){R.emplace_back(S, nodes[0]);R.emplace_back(nodes[0], E);}
    return R;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    N = rnd.next(2, MAX_N);
    int M = rnd.next(1, MAX_M);
    int Q = rnd.next(1, MAX_Q);

    vector<int> A;
    for(int i = N-2; i; i--) {A.push_back(rnd.next(1, N));}
    vector<pair<int, int>> R = prufer_to_tree(N, A);

    cout << N << sp << M << sp << Q << endl;

    set<pair<int, int>> st;
    vector<pair<int, int>> E;
    for(int i=0;i<M;i++){
        int ind = rnd.next(0, (int)R.size()-1);
        int u = R[ind].first; int v = R[ind].second;
        vector<pair<int, int>> extra = extend_edge(u, v, N);
        for(auto P : extra) {
            int uu=P.first;int vv=P.second;
            if(uu>vv)swap(uu,vv);
            if(st.emplace(uu,vv).second){
                if(rnd.next()>0.5) swap(uu, vv);
                E.emplace_back(uu,vv);
                i++;
                if(i>=M)break;
            }
        }
        if(u>v)swap(u,v);
        while(!st.emplace(u, v).second){u=rnd.next(1, N-1);v=rnd.next(u+1, N);}
        if(rnd.next()>0.5) swap(u, v);
        E.emplace_back(u,v);
    }
    for(int i = 0;i<M;i++){auto P = E[i]; int t = rnd.next(1, MAX_W); cout << P.first << sp << P.second << sp << t << endl;}

    for(int i=Q;i;i--){
        int u,v;
        int ind = rnd.next(0, (int)R.size()-1);u=R[ind].first;v=R[ind].second;
        if(rnd.next() > 0.5) swap(u, v);
        cout << u << sp << v << endl;
    }

    return 0;
}