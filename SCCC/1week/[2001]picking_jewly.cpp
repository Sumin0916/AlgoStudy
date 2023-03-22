#include <iostream>
#include <tuple>
#include <vector>
#define INF 10000000

using namespace std;

int n, m ,k;
int jewly_bit = 0;
int res = -1;
vector<vector<pair<int, int>>> graph(101);

void BFS(int node, int jew_info, int visited, int weight){
    int next_node, max_weight;
    if (node == 1){
        res = min(res, weight);
        return;
    }
    for (pair<int, int> i : graph[node]){
        next_node = i.first; max_weight = i.second;
        if ((visited&(1<<next_node))||(max_weight < weight)){continue;}
        visited |= (1<<next_node);
        if (jew_info&(1<<next_node)){
            jew_info |= (1<<next_node);
            BFS(next_node, jew_info, visited, weight+1);
            jew_info &= ~(1<<next_node);
            BFS(next_node, jew_info, visited, weight);
        }
        else{
            BFS(next_node, jew_info, visited, weight);
        }
        visited &= ~(1<<next_node);
    }
}


int main(void){
    int in_num, a, b, c;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(&graph[0][0], &graph[100][101], INF);
    cin>>n>>m>>k;
    for (int i = 0; i < k; i++){
        cin>>in_num;
        jewly_bit |= (1<<in_num);
    }
    for (int i = 0; i < m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
    }
    //BFS(1, jewly_bit, 0, 0);
    return 0;
}