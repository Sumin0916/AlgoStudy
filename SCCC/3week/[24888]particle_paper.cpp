#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
const ll INF = 9999999999999999;
const int MAX_N = 200001;


typedef pair<ll, int> p;

int main(void){
    ll dist[MAX_N];
    int note_num = 0;
    vector<p> adj[MAX_N];
    vector<int> dp(MAX_N, 0);
    int note[MAX_N];
    int prev_node[MAX_N];
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin>>N>>M;
    for (int i = 0; i < M; i++){
        int s, e;
        ll w;
        cin>>s>>e>>w;
        adj[s].push_back(make_pair(e, w));
        adj[e].push_back(make_pair(s, w));
    }

    for (int i = 1; i < N+1; i++){
        dist[i] = INF;
        dp[i] = -1;
        cin>>note[i];
        note_num += note[i];
    }

    priority_queue<p> PQ;
    PQ.push(p(0, 1));
    dist[1] = 0;
    dp[1] = note[1];
    prev_node[1] = 1;
    while (!PQ.empty()){
        ll cost = -PQ.top().first;
        int curr = PQ.top().second;
        PQ.pop();
        if (dist[curr] < cost){continue;}
        for (auto &a:adj[curr]){
            int next = a.first;
            ll next_cost = cost + a.second;
            if (dist[next] > next_cost){
                dist[next] = next_cost;
                PQ.push(p(-dist[next], next));
                if (dp[next] <= dp[curr] + note[next]){
                    dp[next] = dp[curr] + note[next];
                    prev_node[next] = curr;
                }
            }
            else if (dist[next] > next_cost){
                if (dp[next] <= dp[curr] + note[next]){
                    dp[next] = dp[curr] + note[next];
                    prev_node[next] = curr;
                }
            }
        }
    }
    if (note_num != dp[N]){cout<<-1<<endl;return 0;}
    stack<int> root;
    int a = N;
    root.push(N);
    while(prev_node[a] != a){
        a = prev_node[a];
        root.push(a);
    }
    cout<<root.size()<<'\n';
    while(!root.empty()){
        cout<<root.top()<<" ";
        root.pop();
    }
    cout<<'\n';
    return 0;
}