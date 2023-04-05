#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 200001;
typedef pair<int, int> p;
int note_num = 0;
vector<p> adj[MAX_N];
vector<int> res;

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
    int dist[MAX_N];
    int prev[MAX_N];
    int visited[MAX_N] = {0, };
    int note[MAX_N];
    fill(prev, prev+MAX_N, -1);
    fill(dist, dist+MAX_N, INF);
    dist[1] = 0;
    priority_queue<p, vector<p>, greater<p>> PQ;
    PQ.push(p(0, 1));
    while (!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);
        if(visited[curr]){break;}
        visited[curr] = true;
        for (auto &a:adj[curr]){
            int next = a.first;
            int dis = a.second;
            if (dist[next] > dist[curr]+dis){
                dist[next] = dist[curr]+dis;
                prev[next] = curr;
                PQ.push(p(dist[next], next));
            }
        }
    }
    for (int i = 1; i < N+1; i++){
        int n;
        cin>>n;
        if(n==1){note_num++;}
        note[i] = n;
    }
    int root = N;
    while(root != -1){
        res.push_back(root);
        root = prev[root];
    }
    reverse(res.begin(),res.end());
    for (int i = 0; i < res.size(); i++){
        if (note[res[i]] == 1){
            note[res[i]] = 0;
            note_num--;
        }
    }
    if (note_num == 0){
        cout<<res.size()<<'\n';
        for (auto i: res){
            cout<<i<<' ';
        }
    }
    else{cout<<-1;}
    return 0;
}