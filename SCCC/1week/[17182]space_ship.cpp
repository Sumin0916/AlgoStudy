#include <iostream>
#include <memory>

using namespace std;
bool visited[11] = {false, };
int res = 100001;
int n, k, graph[11][11];

void DFS(int start, int depth, int weight){
    if (depth == n){res = min(res, weight);}
    for (int i = 0; i < n; i++){
        if (start == i){continue;}
        if (!visited[i]){
            visited[i] = true;
            DFS(i, depth+1, weight+graph[start][i]);
            visited[i] = false;    
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
    }
    for (int m = 0; m < n; m++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                graph[i][j] = min(graph[i][j], graph[i][m]+graph[m][j]);
            }
        }
    }
    visited[k] = true;
    DFS(k, 1, 0);
    cout<<res;
    return 0;
}