#include<bits/stdc++.h>
using namespace std;

int N, M;
int stress;
int ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        stress = max(0, stress+t);
        if(stress >= M) ans++;
    }
    cout << ans;
    return 0;
}