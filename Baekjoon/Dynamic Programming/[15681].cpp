#include<bits/stdc++.h>
using namespace std;

int N, R, Q;
int DP[100010];
vector<int> E[100010];
bool V[100010];

int make_depth(int cur){
    int size = 1;
    V[cur]=true;
    for(auto next:E[cur]){
        if(V[next]) continue;
        if(DP[next]) size += DP[next];
        else size += make_depth(next);
    }
    DP[cur] = size;
    return size;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> R >> Q;
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        E[a].emplace_back(b);
        E[b].emplace_back(a);
    }
    make_depth(R);
    for(int i=0; i<Q; i++){
        int a; cin >> a;
        cout << DP[a] << '\n';
    }
    return 0;
}