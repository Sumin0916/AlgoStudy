#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int n, s, e, w;
ll res = 0;
vector<pair<int, ll>> graph[5002];
bool visited[5002] = {false, };

ll DFS(int start, int path){
    ll res = 0;
    for (int i = 0; i < graph[start].size(); i++){
        if (graph[start][i].first==path){continue;}
            res = max(res, DFS(graph[start][i].first, start)+graph[start][i].second);
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i = 0; i < n-1; i++){
        cin>>s>>e>>w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }
    visited[1] = true;
    cout<<DFS(1, -1);
    return 0;
}