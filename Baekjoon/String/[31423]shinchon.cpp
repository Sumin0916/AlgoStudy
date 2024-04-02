#include<bits/stdc++.h>
using namespace std;

int N, S;
vector<string> arr;
vector<int> P;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    P.resize(500050);
    cin >> N;
    for(int i=1; i<=N; i++){
        string a; cin >> a; arr.push_back(a);
    }
    int a, b;
    for(int j=1; j<N; j++){
       cin >> a >> b;
       P[a] = b;
    }


    return 0;
}