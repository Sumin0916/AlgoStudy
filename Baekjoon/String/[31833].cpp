#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
string X;
string Y;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        X+=to_string(a);
    }
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        Y+=to_string(a);
    }
    cout << min(stoll(X), stoll(Y));
    return 0;
}