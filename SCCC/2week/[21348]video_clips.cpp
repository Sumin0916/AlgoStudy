#include<iostream>
#define MAX_LOG_M 31
#define MAX_K 100001

using namespace std;
int sparse_table[MAX_LOG_M][MAX_K];
int answer[MAX_K];

void videos(int K, int M, int S[]) {
    for (int i = 0; i < K; i++){sparse_table[0][i]=S[i];}
    for (int i = 1; i < MAX_LOG_M; i++){
        int tmp;
        for (int j = 0; j < K; j++){
            tmp = sparse_table[i-1][j];
            sparse_table[i][j] = sparse_table[i-1][tmp];
        }
    }
    for (int i = 0; i < K; i++){
        int curr = i;
        for (int j = MAX_LOG_M; 0 <= j; --j){
            if (M & (1<<j)){curr = sparse_table[j][curr];}
        }
        answer[i] = curr;
    }
}


int clip(int I){
    return answer[I];
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
    videos(k, m, s);
    int t;
    cin>>t;
    for (int i = 0; i < t; i++){
        int ab;
        cin>>ab;
        ab=clip(ab);
        cout<<ab;
    }
    return 0;
}