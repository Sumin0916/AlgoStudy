#include <iostream>
#include <algorithm>

using namespace std;
int INF = 1000000000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int dp[51][51][1<<6];
char map[51][51];
pair<int, int> minsik;

void BFS(int row, int col, int depth, int key){
    char now_stat = map[row][col];
    if (now_stat == 1){
        return; 
    }
    if ('a' <= now_stat && now_stat <= 'f'){
        int key_num = now_stat % 'a';
        key |= (1<<key_num); 
        if (dp[row][col][key] < depth){return;}
        dp[row][col][key] = min(dp[row][col][key], depth);
    }
    int next_row, next_col;
    for (int i = 0; i < 4; i++){
        next_row = row + dx[i];
        next_col = col + dy[i];
        if ((-1 < next_row && next_row < n)&&(-1 < next_col && next_col < m)){
            if (map[next_row][next_col]=='')
            BFS(next_row, next_col, depth+1, key);
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    char input_data;
    fill(dp[0][0], dp[51][51], INF);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>input_data;
            if (input_data==0){minsik.first=i;minsik.second=j;}
            map[i][j] = input_data;
        }
    }


    return 0;
}