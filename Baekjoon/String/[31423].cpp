#include<bits/stdc++.h>
using namespace std;

int N, S;
vector<string> arr(500050);
vector<int> P(500050);
vector<int> L(500050);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    arr.push_back("");
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        P[i] = i;
    }

    int a, b;
    for(int j=1; j<N; j++){
       cin >> a >> b;
       L[P[a]] = b;
       P[a] = P[b];
    }
    do {cout<< arr[a];} while(a = L[a]);
    return 0;
}