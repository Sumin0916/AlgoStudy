#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, K;
int DP[505][505];

int main(){
    cin >> N >> K;
    for(int i=0; i<505; i++) for(int j=0; j<505; j++) DP[i][j] = INF;
    for(int i=0; i<=N; i++) {DP[i][1] = i;}

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(i < j){
                DP[i][j] = DP[i][j-1];
                continue;
            }
            for(int m=1; m<i; m++){
                DP[i][j] = min(DP[i][j], 1 + max(DP[m-1][j-1], DP[i-m][j]));
            }
        }
    }
    cout << DP[N][K];
    return 0;
}
