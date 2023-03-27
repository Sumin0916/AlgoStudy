#include<iostream>
#include<algorithm>
#define MAX_LOG_M 31
#define MAX_K 100001
using namespace std;
int global_m;
int sparse_table[MAX_LOG_M][MAX_K];

void videos(int K, int M, int S[]) {
    global_m = M;
    for (int i = 0; i < K; i++){sparse_table[0][i]=S[i];}
    for (int i = 1; i < MAX_LOG_M; i++){
        int tmp;
        for (int j = 0; j < K; j++){
            tmp = sparse_table[i-1][j];
            sparse_table[i][j] = sparse_table[i-1][tmp];
        }
    }
}

int clip(int I){
    int curr = sparse_table[0][I];
    for (int j = MAX_LOG_M; 0 <= j; --j){
        if ((global_m-2) & (1<<j)){
            curr = sparse_table[j][curr];
        }
    }
    return curr;
}
