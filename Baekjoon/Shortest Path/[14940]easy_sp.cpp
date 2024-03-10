#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
typedef tuple<int, int, int> T;

int N, M;
int graph[1010][1010];
int visited[1010][1010] = {0, };
const int INF = 99999999;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    priority_queue<T> Q;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M;j++) {
            cin >> graph[i][j];
            visited[i][j] = INF;
            if(graph[i][j] == 2) { Q.push(T(i, j, 0)); visited[i][j] = 0; }
            if(graph[i][j] == 0) { visited[i][j] = 0; }
        }
    }

    while(!Q.empty()) {
        T now = Q.top(); Q.pop();
        int x = get<0>(now); int y = get<1>(now); int cost = get<2>(now);
        if(visited[x][y] < cost) continue;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                if((graph[nx][ny] == 1) && (cost+1 < visited[nx][ny])) {
                    Q.push(T(nx, ny, cost+1));
                    visited[nx][ny] = cost+1;
                }
            }
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M;j++) {
            if(visited[i][j] == INF && graph[i][j] == 1) cout << -1 << ' ';
            else cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}