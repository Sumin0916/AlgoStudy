#include<bits/stdc++.h>
using namespace std;

int N;
int P[10010];
vector<int> E[10010];
int DP[10010][1];
bool V[10010];

void dfs(int cur){
    if(V[cur]) return;
    V[cur]=true;
    DP[cur][0] = 0;
    DP[cur][1] = P[cur];
    for(auto next:E[cur]){
        if(V[next]) continue;
        dfs(next);
        DP[cur][1] += DP[next][0];
        DP[cur][0] += max(DP[next][1], DP[next][0]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> P[i];
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        E[a].emplace_back(b);
        E[b].emplace_back(a);
    }
    dfs(1);
    cout << max(DP[1][0], DP[1][1]);
    return 0;
}