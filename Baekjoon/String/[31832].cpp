#include<bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++){
        int numc=0, num_L=0, num_N=0, num_B=0;
        cin >> S;
        int SL = S.length();
        for(int j=0; j<SL; j++){
            char now = S[j];
            if(97 <= now && now <= 122) num_L++;
            else if(48 <= now && now <= 57) num_N++;
            else if(65 <= now && now <= 90) num_B++;
        }
        if(SL > 10) continue;
        if(num_B > num_L) continue;
        if(SL == num_N) continue;
        cout << S;
        return 0;
    }
    return 0;
}