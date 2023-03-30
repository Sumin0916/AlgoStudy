#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<tuple>
#define INF 987654321

using namespace std;
vector<tuple<int, int, int>> node;
int len_table[18][18];
char graph[1001][1001];
bool visited[1001][1001] = {false, };
int dp[18][1<<18];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, K;

int find_len(pair<int, int> start, pair<int, int> end){
    memset(visited, false, sizeof(visited));
    int end_row = end.first; int end_col = end.second;
    queue<tuple<pair<int, int>, int>> Q;
    Q.push(make_tuple(start, 0));
    while(!Q.empty()){
        tuple<pair<int, int>, int> node = Q.front(); Q.pop();
        int row = get<0>(node).first; int col = get<0>(node).second; int dis = get<1>(node);

        if (row == end_row && col == end_col){return dis;}

        for (int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow < 0 || nrow >= N || ncol < 0 || ncol >= M){continue;}
            int step = graph[nrow][ncol];

            if (step == '#'){continue;}
            if (visited[nrow][ncol]){continue;}

            visited[nrow][ncol] = true;
            Q.push(make_tuple(make_pair(nrow, ncol), dis+1));
        }
    }
    return INF;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M>>K;
    memset(len_table, INF, sizeof(len_table));
    int cnt = 1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            char tp;
            cin>>tp;
            graph[i][j] = tp;
            if (tp == 'N'){
                node.push_back(make_tuple(i, j, cnt));
                cnt++;
            }
            else if(tp == 'I'){
                node.push_back(make_tuple(i, j, 17));
            }
            else if (tp == 'U'){
                node.push_back(make_tuple(i, j, 0));
            }
        }
    }

    for (int i = 0; i < node.size(); i++){
        for (int j = i+1; j < node.size(); j++){
            tuple<int, int, int> start_info = node[i]; tuple<int, int, int> end_info = node[j];
            int s_num = get<2>(start_info); int e_num = get<2>(end_info);
            pair<int, int> s_pair = make_pair(get<0>(start_info), get<1>(start_info));
            pair<int, int> e_pair = make_pair(get<0>(end_info), get<1>(end_info));
            len_table[s_num][e_num] = find_len(s_pair, e_pair);
            len_table[e_num][s_num] = len_table[s_num][e_num];
        }
    }
    return 0;
}