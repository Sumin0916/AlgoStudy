#include<iostream>
#include<algorithm>
#define MAX_LOG_M 31
#define MAX_K 100001
int global_m;
using namespace std;
int sparse_table[MAX_LOG_M][MAX_K];

void videos(int K, int M, int S[]) {
    global_m = M;
    for (int i = 0; i < K; i++){sparse_table[0][i]=S[i];}
    for (int i = 1; i < MAX_LOG_M; i++){
        for (int j = 0; j < K; j++){
            sparse_table[i][j] = sparse_table[i-1][sparse_table[i-1][j]];
        }
    }
}


int clip(int I){
    for (int j = MAX_LOG_M; 0 <= j; --j){
        if ((global_m-1) & (1<<j)){
            I = sparse_table[j][I];
        }
    }
    return I;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,k,s[100000];
    cin>>k>>m;
    for (int i = 0; i < 100001; i++){
        int tmp;
        cin>>tmp;
        s[i] = tmp;
    }
    videos(4, 2, s);
    cout<<clip(3)<<clip(1);
    return 0;
}
