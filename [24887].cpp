#include<bits/stdc++.h>
using namespace std;

int N, M, ans=-1;
int W[200002];

int solve(int s, int e){
    if(s>e) return -1;
    int pivot = (s+e)/2;
    cout << pivot << '\n';
    int max_sum = -1;
    for(int g=1; g<N-pivot; g++){
        int sum=0;
        for(int i=0; i<g; i++) sum += W[i];
        if(sum>=M) break;
        for(int i=g+pivot; i<N; i++) sum += W[i];
        max_sum = max(max_sum, sum);
    }
    if(max_sum > M) return solve(pivot, e);
    else if(max_sum < M) return solve(s, pivot-1);
    else return pivot;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> W[i];
    ans = solve(1, N-2);
    if(ans == -2) cout << "Free!";
    else cout << ans;
    return 0;
}
