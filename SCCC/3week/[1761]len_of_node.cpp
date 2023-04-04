#include<iostream>
#include<vector>
#include<memory.h>

const int MAX =20;
using namespace std;

vector<pair<int, int>>adj[40001];
int parent[40001][MAX];
int level[40001];
int dis_node[40001];
int visit[40001];

void dfs(int curr, int lev, int cost){
    visit[curr] = 1;
    level[curr] = lev;
    dis_node[curr] = cost;
    for (pair<int, int> info : adj[curr]){
        int next = info.first; int weight = info.second;
        if (visit[next]){continue;}
        parent[next][0] = curr;
        dfs(next, lev+1, cost+weight);
    }
}

int lca(int u, int v){
	if(level[u] > level[v]) swap(u, v);
	int diff = level[v] - level[u];
	for(int i=0; diff; i++){
		if(diff & 1) v = parent[v][i];
		diff >>= 1;
	}
	if(u == v) return u;
	for(int i=19; i>=0; i--){
		if(parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
	}
	return parent[u][0];
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin>>N;
    level[1] = 1, parent[1][0] = 0; visit[1] = 1; dis_node[1] = 0;
    for (int i = 0; i < N-1; i++){
        int s, e, w;
        cin>>s>>e>>w;
        adj[s].push_back(make_pair(e, w));
        adj[e].push_back(make_pair(s, w));
    }
    dfs(1, 0, 0);
    for (int i = 1; i < MAX; i++){
        for (int j = 1; j < N+1; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    int M;
    cin>>M;
    for (int i = 0; i < M; i++){
        int s, e;
        cin>>s>>e;
        int m = lca(s, e);
        cout<<dis_node[s]+dis_node[e]-2*dis_node[m]<<'\n';
    }
    return 0;
}