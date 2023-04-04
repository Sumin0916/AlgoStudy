#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<tuple>
#define INF 1000000

using namespace std;
vector<tuple<int, int, int>> node;

char graph[1001][1001];
int len_table[19][19];
int dp[19][1<<19];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, K;
int end_visited = 0;

int find_len(pair<int, int> start, pair<int, int> end){
    bool visited[1001][1001] = {false, };
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

int TSP(int node, int visited){
    int &weight = dp[node][visited];
    if (weight != -1){return weight;}
    if (visited == end_visited){
        return len_table[node][18];
    }
    weight = INF;
    for (int i = 1; i < 19; i++){
        if (len_table[node][i] == INF || visited & (1<<i)){continue;}
        weight = min(weight, TSP(i, visited | (1<<i)) + len_table[node][i]);
    }
    return weight;
}

int main(void){
    for (int i = 0; i < 19; i++){for (int j = 0; j < 19; j++){len_table[i][j] = INF;}}
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M>>K;
    int cnt = 2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            char tp;
            cin>>tp;
            graph[i][j] = tp;
            if (tp == 'N'){
                node.push_back(make_tuple(i, j, cnt));
                end_visited |= (1<<cnt);
                cnt++;
            }
            else if(tp == 'I'){
                node.push_back(make_tuple(i, j, 18));
            }
            else if (tp == 'U'){
                node.push_back(make_tuple(i, j, 1));
                end_visited |= (1<<1);
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
    cout<<TSP(1, (1<<1));
    return 0;
}