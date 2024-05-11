#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[500005], B[500005], C[500005], N;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){ int n; cin >> n; A[i] = n; B[n] = i;}
    for(int i=1; i<=N-1; i++){
        if(i==A[i]) continue;
        C[i]+=abs(i-B[i]); C[A[i]]+=abs(i-B[i]); int c = B[i];
        swap(B[i], B[A[i]]); swap(A[i], A[c]);
    }
    for(int i=1; i<=N; i++)cout<<C[i]<<' ';
    return 0;
}