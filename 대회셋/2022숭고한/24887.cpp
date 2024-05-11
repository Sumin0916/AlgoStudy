#include<bits/stdc++.h>
using namespace std;

int N, M, ans=-1;
int A[200002];

int solve(int s, int e){
    if(s > e) return -1;
    int pivot = (s+e)/2;
    if(s==e) return s;
    int max_w = -1;
    cout << pivot << '\n';
    for(int i=1; i<N-pivot-2; i++){
        int sum=0;
        for(int j=0; j<i; j++) sum+=A[j];
        for(int j=i+pivot; j<N; j++) sum+=A[j];
        max_w = max(sum, max_w);
    }
    if(max_w < M) return solve(s, pivot-1);
    if(max_w >= M) return solve(pivot, e);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> A[i];
    ans = solve(2, N-2);
    for(int i=0; i<N; i++) if(A[i]>= M) ans = -2;
    if(ans==-2) cout << "Free!";
    else cout << ans;
    return 0;
}