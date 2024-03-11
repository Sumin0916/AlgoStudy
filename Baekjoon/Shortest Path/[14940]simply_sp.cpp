#include<iostream>
#include<queue>

using namespace std;
typedef pair<int, int> P;

int N,M;
int graph[1010][1010];
int visited[1010][1010] = {0, };
const int INF = 9999999;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> N >> M;
    queue<P> Q;
    for(int i=0; i < 1010; i++) for(int j=0; j < 1010; j++)visited[i][j] = INF;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> graph[N][M];
            if(graph[N][M] == 2) Q.push(P(N,M));
        }
    }


    return 0;
}