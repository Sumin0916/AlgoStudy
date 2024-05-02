#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int C = 1000000007;
int T, L;
ll DP[5050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    DP[2] = 1; DP[0] = 1;
    for(int i=4; i<=5000; i+=2){
        DP[i] = DP[i-2];
        for(int j=2; j<=i-2; j+=2){
            DP[i] += (DP[i-j]*DP[j-2]);
            DP[i] %= C;
        }
    }
    cin >> T;
    while(T--){ 
        cin >> L;
        cout << DP[L] << '\n';
    }
    return 0;
}