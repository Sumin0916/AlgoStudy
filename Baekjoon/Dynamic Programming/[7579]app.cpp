#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll MA[101];
ll DP[10100];
int CI[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int size=0;
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> MA[i];
    for(int i=1; i<=N; i++){
        cin >> CI[i]; size+=CI[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=size; j>=CI[i]; j--){
            DP[j] = max(DP[j], DP[j-CI[i]]+MA[i]);
        }
    }
    for(int j=0; j<=size; j++){
        if(DP[j] >= M) {cout << j; return 0;}
    }
    return 0;
}