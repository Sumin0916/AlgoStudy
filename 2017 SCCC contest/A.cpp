#include<bits/stdc++.h>
using namespace std;

int N, R;
int M[101];
int main(){
    int flag = 0;
    cin >> N;
    for(int i=0; i<101; i++){
        M[i] = -1;
    }
    while(N--){
        int e, n;
        cin >> e >> n;
        M[e] = n;
    }
    cin >> R;
    for(int i=0; i<R; i++){
        int L; cin >> L;
        vector<int> T;
        for(int i=0; i<L; i++){
            int tt; cin >> tt;
            if(M[tt] != -1) T.emplace_back(M[tt]);
        }
        if(T.size() != L) cout << "YOU DIED\n";
        else{
            for(auto a:T) cout << a << ' ';
            cout << '\n';
        }
    }
    return 0;
}