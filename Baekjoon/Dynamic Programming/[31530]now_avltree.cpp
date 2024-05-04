#include<iostream>
using namespace std;
typedef unsigned long long ll;
const int C = 1000000007;
int T, H, SN;
ll DP[1000001][7];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    for(int i=0; i<7; i++) {DP[0][i] = DP[1][i] = 1;}
    for(int i=2; i<=1000000; i++){
        DP[i][0] = DP[i-1][0]; DP[i][1] = DP[i-1][1]; DP[i][2] = DP[i-1][2];
        DP[i][3] = DP[i-1][3]*DP[i-1][3] + DP[i-1][3]*DP[i-2][3]; DP[i][3] %= C;
        DP[i][4] = 2*DP[i-1][4]*DP[i-2][4]; DP[i][4] %= C;
        DP[i][5] = DP[i-1][5]*DP[i-1][5] + DP[i-1][5]*DP[i-2][5]; DP[i][5] %= C;
        DP[i][6] = DP[i-1][6]*DP[i-1][6] + 2*DP[i-1][6]*DP[i-2][6]; DP[i][6] %= C;
    }
    while(T--){
        int a, b, c;
        cin >> H >> SN;
        if(SN == 1){
            cin >> a;
            cout << DP[H][a+1] << '\n';
        }
        else if(SN == 2){
            cin >> a >> b;
            cout << DP[H][a+b+4] << '\n';
        }
        else if(SN == 3){
            cin >> a >> b >> c;
            cout << DP[H][6] << '\n';
        }
    }
    return 0;
}