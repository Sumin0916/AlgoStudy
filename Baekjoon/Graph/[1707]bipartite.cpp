#include<bits/stdc++.h>
using namespace std;

int K, V, E;
int VV[20020];
vector<int> Edges[20020];

bool is_bi(int start){
    queue<int> Q;
    Q.push(start);
    VV[start] = 1;
    while(!Q.empty()){
        int now = Q.front(); Q.pop();
        int next_state = 1 - VV[now];
        for(auto next:Edges[now]){
            if(VV[next] == VV[now]) return false;
            if(VV[next] != -1) continue;
            VV[next] = next_state;
            Q.push(next);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> K;
    while(K--){
        cin >> V >> E;
        bool res = true;
        for(int i=0; i<20020; i++) {Edges[i].clear();VV[i] = -1;}
        for(int i=0; i<E; i++){
            int a, b; cin >> a >> b;
            Edges[a].emplace_back(b);
            Edges[b].emplace_back(a);
        }
        for(int i=1; i<=V; i++){
            if(VV[i] == -1){
                if(!is_bi(i)) res = false;
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
}