#include<bits/stdc++.h>
using namespace std;

int L, T, N;
vector<pair<int, int>> A;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    cin >> L >> T >> N;
    for(int i=1; i<=N; i++){
        int a; char b; cin >> a >> b;
        if(b=='D') {
            a += T;
            if(a>=L){
                if((a/L)%2==1){
                    a = L - a%L;
                }
                else{
                    a %= L;
                }
            }
        }
        else {
            a -= T;
            if(a<0){
                a=-a;
                if((a/L)%2==0){
                    a %= L;
                }
                else{
                    a = L - a%L;
                }
            }
        }
        A.emplace_back(a, i);
    }
    sort(A.begin(), A.end());
    for(auto i:A){
        cout << i.first << ' ';
    }
    return 0;
}