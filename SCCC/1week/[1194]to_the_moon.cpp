#include <iostream>
#include <algorithm>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool dp[51][51][1<<6] = {false, };
char map[51][51];
int res = 100000000;
pair<int, int> minsik;

void BFS(int row, int col, int depth, int key){
    char now_stat = map[row][col];
    cout<<row<<col<<key<<depth<<endl;
    if (now_stat == '1'){
        cout<<"im depth:"<<depth<<endl;
        res = min(res, depth);
        return;
    }
    else if ('a' <= now_stat && now_stat <= 'f'){
        int key_num = int(now_stat - 'a');
        key |= (1<<key_num); 
    }
    else if ('A' <= now_stat && now_stat <= 'F'){
        int key_num = int(now_stat - 'A');
        if (int(key&(1<<key_num))==0){return;}
    }
    int next_row, next_col;
    for (int i = 0; i < 4; i++){
        next_row = row + dx[i];
        next_col = col + dy[i];
        if ((-1 < next_row && next_row < n)&&(-1 < next_col && next_col < m)){
            if (map[next_row][next_col]=='#'){continue;}
            if (dp[next_row][next_col][key]){continue;}
            dp[next_row][next_col][key] = true;
            BFS(next_row, next_col, depth+1, key);
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input_data;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>input_data;
        for (int j = 0; j < m; j++){
            if (input_data[j]=='0'){minsik.first=i;minsik.second=j;}
            map[i][j] = input_data[j];
        }
    }
    BFS(minsik.first, minsik.second, 0, 0);
    if (res==100000000){cout<<-1;}
    else{cout<<res;}
    return 0;
}