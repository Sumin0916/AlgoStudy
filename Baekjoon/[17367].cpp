#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int N;
ld dp[1001][7][7];
ld ans = 0;

ld cal_p(int a, int b, int c){
    ld res;
    if(a==b && b==c) res = 10000 + a * 1000;
    else if(a==b || a==c) res = 1000 + a * 100;
    else if(b==c) res = 1000 + b * 100;
    else res = max(a, max(b, c)) * 100;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int n=1; n<=N; n++){
        for(int a=1; a<=6; a++){
            for(int b=1; b<=6; b++){
                for(int c=1; c<=6; c++){
                    ld curr = cal_p(a, b, c);
                    ld before_expected = dp[n-1][b][c];
                    before_expected /= 6;
                    if(n==N){
                        dp[n][a][b] += curr;
                    }
                    else{
                        dp[n][a][b] += max(before_expected, curr);
                    }
                }
            }
        }
    }
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            ans += dp[N-2][i][j];
        }
    }
    cout << fixed;
    cout.precision(11);
    cout << ans/216;
    return 0;
}