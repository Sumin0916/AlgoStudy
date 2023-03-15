#include <iostream>
#include <memory>

using namespace std;

int main(void){
    int n, k, graph[11][11];
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    return 0;
}