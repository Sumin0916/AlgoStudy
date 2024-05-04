#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll ans = 0;
ll A, F, S, E;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A;
        if(A){
            if(!F) F=i;
            ans += A; E = i;
            if(S) ans += (i-S)/2;
            S = i; 
        }
    }
    ans += (N+F-E)/2;
    cout << ans;
}