#include<bits/stdc++.h>
using namespace std;
int N;
string Q;
bool ans;

bool solve(int i){
    if(i == 0) return (Q[0] == 'T');
    if(Q[i-1] == '&') return (Q[i] == 'T') && solve(i-2);
    else return (Q[i] == 'T') || solve(i-2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++){
        string a; cin >> a;
        Q+=a;
    }    
    char a; cin >> a;
    ans = (a =='T');
    bool QA = solve(N-1);
    if(ans == QA) {cout << 0;}
    else if(N>=3){
        bool QB = solve(N-3);
        if(QA){
            if(QB){
                if(Q[N-1]=='T' && Q[N-2]=='|') cout << 2;
                else cout << 1;
            }
            else{
                cout << 1;
            }
        }
        else{
            if(QB){
                cout << 1;
            }
            else{
                if(Q[N-1]=='F'&&Q[N-2]=='&') cout << 2;
                else cout << 1;
            }
        }
    }
    else{
        cout << 1;
    }
    return 0;
}