#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 200001;
typedef pair<int, int> p;
long long dist[MAX_N];
int note_num = 0;
vector<p> adj[MAX_N];
vector<int> res;
vector<int> n_count(MAX_N, 0);
int note[MAX_N];

void res_bt(int node, int pre){
    if (node == 1){
        cout<<note_num<<'\n';
        for (int i = res.size()-1; i > -1; i--){
        cout<<res[i]<<" ";
    }
        exit(0);
    }

    for (p &a : adj[node]){
        int n = a.first; int d = a.second;
        if (pre == n){continue;}
        if (dist[node] != dist[n]+d){continue;}
        if (n_count[node] != n_count[n]+note[node]){continue;}
        res.push_back(n);
        res_bt(n, node);
        res.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; i++){
        int s, e, w;
        cin>>s>>e>>w;
        adj[s].push_back(make_pair(e, w));
        adj[e].push_back(make_pair(s, w));
    }
    fill(dist, dist+MAX_N, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push(p(0, 1));
    for (int i = 1; i < N+1; i++){
        cin>>note[i];
        note_num += note[i];
    }
    n_count[1] = note[1];
    while (!PQ.empty()){
        int curr = PQ.top().second;
        long long cost = PQ.top().first;
        PQ.pop();
        if (dist[curr]< cost){continue;}
        for (p &a:adj[curr]){
            int next = a.first;
            long long next_cost = cost + a.second;
            if (dist[next] > next_cost){
                n_count[next] = max(n_count[next], n_count[curr]+note[next]);
                dist[next] = next_cost;
                PQ.push(p(dist[next], next));
            }
            else if (dist[next] == next_cost){n_count[next] = max(n_count[next], n_count[curr]+note[next]);}
        }
    }

    if (note_num != n_count[N]){cout<<-1;return 0;}
    res.push_back(N);
    res_bt(N, 0);
    return 0;
}