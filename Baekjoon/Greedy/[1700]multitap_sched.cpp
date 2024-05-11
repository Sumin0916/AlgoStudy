#include<bits/stdc++.h>
using namespace std;
int N, K, A[101], ans;
map<int, int> M;

int main(){
    cin >> N >> K;
    for(int i=0; i<K; i++)  cin >> A[i];
    for(int i=0; i<K; i++){
        if(M.find(A[i]) != M.end()) continue;
        if(M.size() == N){
            int T=-1, R;
            for(auto j:M){
                int flag = 0;
                int now = j.first;
                for(int m=i; m<K; m++){
                    if(A[m] == now){
                        flag = 1;
                        if(m > T){
                            T = m;
                            R = now;
                        }
                        break;
                    }
                }
                if(!flag) {R = now;break;}
            }
            M.erase(R);
            ans++;
        }
        M[A[i]] = 1;
    }
    cout << ans;
    return 0;
}