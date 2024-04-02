#include<bits/stdc++.h>
using namespace std;

long long T, N, K;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> N >> K;
        while(N&&K){
            N=N>>1; --K;
        }
        cout<<(N+1)/2<<'\n';
    }
    return 0;
}