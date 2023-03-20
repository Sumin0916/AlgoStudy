#include <iostream>
#include <algorithm>

using namespace std;
int INF =100000000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int dp[51][51][1<<6];
char map[51][51];
int res = INF;
pair<int, int> minsik;

void BFS(int row, int col, int depth, int key){
    char next_stat;
    int next_row, next_col;
    dp[row][col][key] = depth;
    for (int i = 0; i < 4; i++){
        int next_key = key;
        next_row = row + dx[i];
        next_col = col + dy[i];
        next_stat = map[next_row][next_col];
        if ((-1 < next_row && next_row < n)&&(-1 < next_col && next_col < m)){
            if (next_stat =='#'){continue;}
            else if ('a' <= next_stat && next_stat <= 'f'){
                next_key |= (1<<int(next_stat - 'a'));
            }
            if (next_stat == '1'){
                res = min(res, depth+1);
                return;
                }
            else if ('A' <= next_stat && next_stat <= 'F'){
                if ((key&(1<<int(next_stat)- 'A'))==0){continue;}
                }
            if (dp[next_row][next_col][key] <= depth+1){continue;}
            BFS(next_row, next_col, depth+1, next_key);
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input_data;
    cin>>n>>m;
    fill(&dp[0][0][0], &dp[50][50][1<<6], INF);
    for (int i = 0; i < n; i++){
        cin>>input_data;
        for (int j = 0; j < m; j++){
            if (input_data[j]=='0'){minsik.first=i;minsik.second=j;}
            map[i][j] = input_data[j];
        }
    }
    BFS(minsik.first, minsik.second, 0, 0);
    if (res==INF){cout<<-1;}
    else{cout<<res;}
    return 0;
}