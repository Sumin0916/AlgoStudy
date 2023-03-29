#include<iostream>
#include<queue>
#include<tuple>
#define INF 1000000000
using namespace std;
int graph[1001][1001];
int dp[18][1<<18];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill_n(dp, 18, INF);
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
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(start_point.first, start_point.second, 0));
    while (!Q.empty()){
        tuple<int, int, int> curr = Q.front(); Q.pop();
        get<>curr;
    }
    return 0;
}