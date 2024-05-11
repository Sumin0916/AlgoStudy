#include<bits/stdc++.h>
using namespace std;
typedef pair<int, char> P;
int main(){
    int A; int B; string C;
    vector<int> D;
    vector<P> E;
    for(int i=3; i; i--){
        cin >> A >> B >> C;
        D.emplace_back(B%100);
        E.emplace_back(A, C[0]);
    }
    sort(D.begin(), D.end());
    sort(E.begin(), E.end(), [](auto &a, auto &b){return a.first > b.first;});
    for(auto &i:D) cout << i;
    cout << '\n';
    for(auto &i:E) cout << i.second;
    return 0;
}