#include<iostream>
#include<queue>

using namespace std;
typedef pair<int, int> P;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt=0;
char graph[606][606];
int visited[606][606] = {0, };

int main() {
    cin >> N >> M;
    queue<P> Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'I'){ Q.push(P(i,j)); }
        }
    }
    while(!Q.empty()){
        P now = Q.front();Q.pop();
        visited[now.first][now.second] = 1;
        if(graph[now.first][now.second] == 'P') {++cnt;}
        for(int i=0;i<4;i++){
            int nx = now.first + dx[i]; int ny = now.second + dy[i];
            if(0<=nx && nx < N && 0 <= ny && ny < M){
                if(graph[nx][ny] != 'X' && (!visited[nx][ny])){
                    Q.push(P(nx,ny));
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    if(cnt)cout<<cnt;
    else cout<<"TT";
    return 0;
}