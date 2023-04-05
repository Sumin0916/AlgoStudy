#include<iostream>
#include<vector>
#include<memory.h>

#define MAX_LOG_N 18
#define MAX_N 100001
using namespace std;
int sparse_table[MAX_LOG_N][MAX_N];
int level[MAX_N];
vector<int> tree[MAX_N];


void dfs(int curr){
    for (int n : tree[curr]){
        if(level[n] == -1){
            sparse_table[0][n] = curr;
            level[n] = level[curr] + 1;
            dfs(n);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin>>N;
    for (int i = 0; i < N-1; i++){
        int s, e;
        cin>>s>>e;
        s--;e--;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    memset(sparse_table, -1, sizeof(sparse_table));
    fill(level, level+N, -1);
    level[0] = 0;
    dfs(0);
    for (int i = 0; i < MAX_LOG_N-1; i++){
        for (int j = 1; j < N; j++){
            if (sparse_table[i][j] != -1)
            sparse_table[i+1][j] = sparse_table[i][sparse_table[i][j]];
        }
    }
    cin>>M;
    for (int i = 0; i < M; i++){
        int s, e;
        cin>>s>>e;
        s--;e--;
        if (level[s] < level[e]){swap(s, e);}
        int diff = level[s] - level[e];
        for (int j = 0; diff; j++){
            if (diff%2) s = sparse_table[j][s];
            diff /= 2;
        }
        if (s != e){
            for (int j = MAX_LOG_N-1; j >= 0; --j){
                if (sparse_table[j][s] != -1 && sparse_table[j][e] != sparse_table[j][s]){
                    s = sparse_table[j][s];
                    e = sparse_table[j][e];
                }
            }
            s = sparse_table[0][s];
        }
        cout<<s+1<<'\n';
    }
    return 0;
}