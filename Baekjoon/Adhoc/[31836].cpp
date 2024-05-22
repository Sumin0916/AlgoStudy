#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    if(N%3==2){
        A.emplace_back(2);
        B.emplace_back(1);
    }
    for(int i=(N%3)+1; i<=N; i++){
        if(i%3 == (N%3)) A.emplace_back(i);
        else B.emplace_back(i);
    }
    cout << A.size() << '\n';
    for(auto i:A) cout << i << ' ';
    cout << '\n';
    cout << B.size() << '\n';
    for(auto i:B) cout << i << ' ';
    return 0;
}