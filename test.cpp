#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, B;
string res;

int main(){
    cin >> N >> B;
    while(N!=0){
        char A = N%B;
        if(A>=10) A+=55;
        else A+=48;
        res += A; 
        N/=B;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}