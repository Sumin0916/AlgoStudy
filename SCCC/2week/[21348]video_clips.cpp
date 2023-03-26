#include<iostream>
#include<algorithm>
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
            if (M & (1<<j)){
                curr = sparse_table[j][curr];
            }
        }
        answer[i] = curr;
        cout<<"answer"<<i<<"="<<curr<<endl;
    }
}


int clip(int I){
    // int *ind;
    // ind = find(sparse_table[0], sparse_table[0]+MAX_K, I);
    //answer[ind-sparse_table[0]];
    return answer[I];
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[4] = {3, 2, 1, 0};
    videos(4, 2, arr);
    cout<<clip(3)<<clip(1);
    return 0;
}
