#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> T;
int N, M;
int graph[101][101] = {0, };
int table[101][101] = {0, };
int visited[101][101] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int djikstra(){
    priority_queue<T> nodes;
    nodes.push(T(0, 1, 1));
    table[1][1] = 0;
    while(!nodes.empty()){
        int cost, x, y;
        tie(cost, x, y) = nodes.top();
        cost *= -1;
        nodes.pop();
        visited[x][y] = 1;
        if (cost > table[x][y]) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];int ny = y + dy[i];
            if((1<=nx) && (nx <= N) && (1<=ny) && (ny<=M)){
                if(!visited[nx][ny] && (table[nx][ny] > graph[nx][ny] + cost)) {
                    table[nx][ny] = graph[nx][ny] + cost;
                    nodes.push(T(-table[nx][ny], nx, ny));
                }
            }
        }
    }
    return table[N][M];
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&graph[i][j]);
            table[i][j] = 9999999;
        }
    }
    cout << djikstra();
    return 0;
}
