#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> T;
int N, M, S, ans;
int P[2020];
vector<T> E;

int find(int a){
    if(P[a]==a)return a;
    return P[a] = find(P[a]);
}

int merge(int a, int b){
    int pa = find(a); int pb = find(b);
    if(pa==pb) return 0;
    P[pa] = P[pb] = min(pa, pb);
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=1; i<2020; i++)P[i]=i;
    cin >> N >> M >> S;
    while(M--){
        int u,v,w;
        cin >> u >> v >> w;
        E.emplace_back(w, u, v);
    }
    while(N--)cin>>M;
    sort(E.begin(), E.end());
    for(T &i:E){
        int u = get<1>(i); int v = get<2>(i);
        if(!merge(u, v)) continue;
        ans+=get<0>(i);
    }
    cout << ans;
    return 0;
}