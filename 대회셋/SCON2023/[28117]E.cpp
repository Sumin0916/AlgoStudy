#include<bits/stdc++.h>
using namespace std;
int ans=1;
int N;
int DP[21];
string S;

int main(){
    cin >> N >> S;
    DP[0] = DP[1] = 1; 
    for(int i=2; i<21; i++){DP[i] = DP[i-1] + DP[i-2];}
    for(int i=0; i<N-3; i++){
        int c = 0;
        while((S.substr(i, 4)).compare("long") == 0){
            c++;
            i+=4;
        }
        ans*=DP[c];
    }
    cout << ans;
    return 0;
}