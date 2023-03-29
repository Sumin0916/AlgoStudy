#include<iostream>
#include<queue>
#include<tuple>
#include<memory.h>

#define INF 1000000000
using namespace std;
int graph[1001][1001];
bool visited[1001][1001] = {false, };
bool dp[17][1<<17] = {false, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int res = INF;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K, cnt=1;
    pair<int, int> end_point, start_point;
    char data;
    cin>>N>>M>>K;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin>>data;
            if (data == '#'){graph[i][j] = -1;}
            else if (data == '.'){graph[i][j] = 0;}
            else if (data == 'U'){start_point.first=i;start_point.second=j;}
            else if (data == 'I'){graph[i][j] = 0; end_point.first=i;end_point.second=j;}
            else if (data == 'N'){graph[i][j] = cnt; cnt++;}
        }
    }
    queue<tuple<int, int, int, int, int>> Q;
    Q.push(make_tuple(start_point.first, start_point.second, 0, 0, 0));
    int now_row, now_col, depth, get_info, get_count;
    while (!Q.empty()){
        tuple<int, int, int, int, int> curr = Q.front(); Q.pop();
        now_row = get<0>(curr); now_col = get<1>(curr); get_info = get<2>(curr); get_count = get<3>(curr); depth = get<4>(curr);
        cout<<'('<<now_row<<", "<<now_col<<") :"<<graph[now_row][now_col]<<"get_count: "<<get_count<<endl;
        if (now_row == end_point.first && now_col == end_point.second && get_count == K){
            res = min(res, depth);
            continue;
        }
        for (int i = 0; i < 4; i++){
            int next_row = now_row + dx[i];
            int next_col = now_col + dy[i];
            int next_get_count = get_count;
            int next_stat = graph[next_row][next_col];
            int next_get_info = get_info;
            if (next_col < 0 || next_col > M-1 || next_row < 0 || next_row > N-1){continue;}
            if (next_stat == -1){continue;}
            else if (next_stat != 0){
                if (!(next_get_info & (1<<next_stat))){
                    next_get_info |= (1<<next_stat);
                    next_get_count += 1;
                }
                if (dp[next_stat][get_info]){continue;}
                dp[next_stat][get_info] = true;
            }
            if (visited[next_row][next_col]){continue;}
            visited[next_row][next_col] = true;
            Q.push(make_tuple(next_row, next_col, next_get_info, next_get_count, depth+1));
        }
    }
    cout<<res;
    return 0;
}