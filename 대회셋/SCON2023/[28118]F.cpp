#include<bits/stdc++.h>
using namespace std;
int P[41];
int N, M, ans;
int find(int a){
    if(P[a]==0) return a;
    return P[a] = find(P[a]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> N >> M;
    while(M--){
        int a, b; cin >> a >> b;
        int pa = find(a); int pb = find(b);
        if(pa == pb) continue;
        P[pa] = pb;
    }
    for(int i=1; i<=N; i++) ans+=(P[i]==0);
    cout << ans-(!ans==0);
    return 0;
}