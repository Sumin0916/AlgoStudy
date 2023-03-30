#include<iostream>
#include<vector>
#define MAX_LOG_N 19
#define MAX_N 100001
using namespace std;
int sparse_table[MAX_LOG_N][MAX_N];
int level[MAX_N] = {0, };
vector<int> tree[MAX_N];


void dfs(int curr, int parent){
    level[curr] = level[parent]+1;
    sparse_table[0][curr] = parent;
    for (auto n : tree[curr]){
        dfs(n, curr);
    }
}

int go(int start, int num){
    int curr = sparse_table[0][start];
    for (int i = MAX_LOG_N; i < 0; --i){
            if ((num-1) & (1<<i)){
                curr = sparse_table[i][curr];
            }        
        }
    return curr;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin>>N;
    for (int i = 0; i < N; i++){
        int s, e;
        cin>>s>>e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    dfs(1, 0);
    for (int i = 1; i < MAX_LOG_N; i++){
        for (int j = 1; j <= MAX_N; j++){
            int temp = sparse_table[i-1][j];
            sparse_table[i][j] = sparse_table[i-1][temp];
        }
    }
    cin>>M;
    for (int i = 0; i < M; i++){
        int s, e, res;
        cin>>s>>e;
        int diff = abs(level[s]-level[e]);
        if (level[s] > level[e]){
            for (int j = 0; j < level[e]; j++){
                int sp = go(s, diff+j);
                int ep = go(e, j);
                if (sp == ep){cout<<sp;continue;}
            }
        }
        else if (level[s] < level[e]){
            for (int i = 0; i < level[s]; i++){
                int sp = go(s, i);
                int ep = go(e, diff+i);
                if (sp == ep){cout<<sp;continue;}
            }
        }
        else{
            cout<<sparse_table[0][s];
        }
    }
    return 0;
}