#include<bits/stdc++.h>
using namespace std;

int N;
string Q;
bool ans;

bool solve(int i){
    bool now = (Q[i] == 'T');
    if(i==N-1) return now;
    if(Q[i+1] == '&') return now && solve(i+1);
    else return now || solve(i+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) {string a; cin >> a; Q+=a;}
    char t; cin >> t;
    ans = (t=='T');
    if(N<=2) {cout<< (ans==(Q[0]=='T'))?0:1;}
    if( ans == solve(0) ) {cout << 0; return 0;}
    if(ans){
        T|
        T&
        F|()
        F&(TorF)
    }
    else{

    }
    return 0;
}