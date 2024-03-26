#include<bits/stdc++.h>
using namespace std;
deque<int> arr;
int S[200002];
int N, Q;

void left_update(){

}

int query(){

}

main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        int a;cin>>a;
        arr.push_back(a);
        S[i] = S[i-1] + a;
    }
    while(Q--){
        int a, b, c; cin >> a >> b;
        if(a==3){
            cin >> c; cout << S[c]-S[b-1] << '\n';
        }
        else {b%=N; update(a, b);}
    }
}