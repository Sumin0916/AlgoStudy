#include<bits/stdc++.h>
using namespace std;

int N, M;
int ans;
int P[41];

int find(int a){
    if(P[a]==0) return a;
    return P[a] = find(P[a]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        int pa = find(a); int pb = find(b);
        if(pa == pb) continue;
        P[pa] = pb;
    }

    for(int i=1; i<=N; i++) if(P[i] == 0) ans++;
    cout << ans-(!ans==0);
}