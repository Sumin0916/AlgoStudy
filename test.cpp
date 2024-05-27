#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
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
=======

int B;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string N; cin >> N >> B;
    
>>>>>>> ae2a1e7419080fa4f41717ce5b3026d1da1ba215
    return 0;
}