#include <iostream>
#include <tuple>
#include <vector>
#define INF 10000000

using namespace std;
typedef pair<int, int> smw;

int n, m ,k;
int jewly_bit = 0;
int jewly_ary[101] = {0, };
int res = 0;
bool visited[101][1<<16] = {false, };
vector<vector<smw>> graph;

void BFS(int node, int jew_info, int weight){
    int next_node, max_weight, next_jew, jew_num;
    if (node == 1){
        res = max(res, weight);
    }
    for (smw i : graph[node]){
        next_node = i.first; max_weight = i.second, next_jew = jew_info;
        jew_num = jewly_ary[node];
        if (jew_info & (1<<jew_num)){
            next_jew &= ~(1<<jew_num);
            if ((visited[next_node][next_jew]) || (max_weight < weight + 1)){continue;}
            visited[next_node][next_jew] = true;
            BFS(next_node, next_jew, weight+1);
            next_jew |= (1<<jew_num);
        }
        if ((visited[next_node][next_jew]) || (max_weight < weight)){continue;}
        visited[next_node][next_jew] = true;
        BFS(next_node, next_jew, weight);
    }
}

int main(void){
    int in_num, a, b, c;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i = 1; i <= k; i++){
        cin>>in_num;
        jewly_ary[in_num] = i;
        jewly_bit |= (1<<i);
    }
    graph.resize(n+1);
    for (int i = 0; i < m; i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a ,c});
    }
    BFS(1, jewly_bit, 0);
    if (jewly_bit&(1<<jewly_ary[1])&&res < k){res++;}
    cout<<res;
    return 0;
}