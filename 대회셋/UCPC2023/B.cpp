#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_V = 50001;
const int INF = 1000000000;
int N, K, M;
int c[MAX_V][MAX_V] = {0}; // c[i][j]: i에서 j로 가는 간선의 용량
vector<int> adj[MAX_V]; // 인접 리스트

int sol(int S, int E) {
    // total: 총 유량, S: 소스, E: 싱크
    int total = 0;
    int f[MAX_V][MAX_V] = {0}; // f[i][j]: i에서 j로 현재 흐르는 유량
    // 증가 경로를 못 찾을 때까지 루프
    while(1){
        // 증가 경로를 BFS로 찾음
        int prev[MAX_V];
        fill(prev, prev+MAX_V, -1);
        queue<int> Q;
        Q.push(S);
        while(!Q.empty() && prev[E] == -1){
            int curr = Q.front();
            Q.pop();
            for(int next: adj[curr]){
                // c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
                // prev[next] == -1: next 정점을 아직 방문하지 않았는가?
                if(c[curr][next]-f[curr][next] > 0 && prev[next] == -1){
                    Q.push(next);
                    prev[next] = curr; // 경로를 기억하기 위해 prev 배열 사용
                    if(next == E) break; // 싱크에 도달하면 나옴
                }
            }
        }
        // 싱크로 가는 경로가 더 없으면 루프 탈출
        if(prev[E] == -1) break;
 
        // 경로상에서 가장 허용치가 낮은 곳을 찾음
        int flow = INF;
        for(int i=E; i!=S; i=prev[i])
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        // 찾은 flow만큼 해당 경로에 유량 흘려줌
        for(int i=E; i!=S; i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        // 총 유량 값 증가
        total += flow;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    // 간선 정보 입력받기
    cin >> N >> K >> M;
    vector<int> info[K+1];

    for(int i=1; i < N+1; i++) {
        int a;
        cin >> a;
        info[a].push_back(i);
    }

    for(int i=0; i<M; i++){
        int x, y, w;
        cin >> x >> y >> w;
        c[x][y] = c[y][x] += w; // 같은 간선이 여러 번 들어올 수 있으므로 +=
        adj[x].push_back(y);
        adj[y].push_back(x); // 역방향 간선도 추가해줘야 함
    }

    cout << sol(1, 4);
    
    // for (int i = 1; i < N+1; i++) {
    //     int res = 0;
    //     for (int j = 0; j < info[i].size(); j++) {
    //         for (int k = j+1; k < info[i].size(); k++) {
    //             res += sol(info[i][j], info[i][k]);
    //         }
    //     }
    //     cout << res << '\n';
    // }
    
}
