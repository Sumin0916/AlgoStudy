#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

const int INF = 999999999999999;
const int MAX_N = 200001;


typedef pair<long long, int> p;
long long dist[MAX_N];
int note_num = 0;
vector<p> adj[MAX_N];
vector<int> n_count(MAX_N, 0);
int note[MAX_N];
int prev_node[MAX_N];

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
    priority_queue<p, vector<p>, greater<p>> PQ;
    PQ.push(p(0, 1));
    for (int i = 1; i < N+1; i++){
        cin>>note[i];
        note_num += note[i];
    }
    n_count[1] = note[1];
    prev_node[1] = 1;
    while (!PQ.empty()){
        int curr = PQ.top().second;
        long long cost = PQ.top().first;
        PQ.pop();
        if (dist[curr]< cost){continue;}
        for (p &a:adj[curr]){
            int next = a.first;
            long long next_cost = cost + a.second;
            if (dist[next] >= next_cost){
                dist[next] = next_cost;
                PQ.push(p(dist[next], next));
                if (n_count[next] <= n_count[curr] + note[next]){
                    n_count[next] = n_count[curr] + note[next];
                    prev_node[next] = curr;
                }
            }
        }
    }
    if (note_num != n_count[N]){cout<<-1;return 0;}
    stack<int> root;
    int a = N;
    root.push(a);
    while(prev_node[a] != a){
        a = prev_node[a];
        root.push(a);
    }
    cout<<note_num<<'\n';
    while(!root.empty()){
        cout<<root.top()<<" ";
        root.pop();
    }
    return 0;
}