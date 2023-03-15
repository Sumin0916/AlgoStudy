#include<iostream>
#include<memory.h>

using namespace std;
int n;
int graph[16][16];
int dp[16][1<<16];

int TSP(int node, int visited){
    int &temp = dp[node][visited];
    if (temp != -1){return temp;}
    if (visited == (1<<n)-1){
        if (graph[node][0] == 0){return 10000000;}
        return graph[node][0];
    }
    temp = 10000000;
    for (int i = 0; i < n; i ++){
        if (graph[node][i]==0 || visited & (1<<i)){continue;}
        temp = min(temp, TSP(i, visited | (1<<i))+graph[node][i]);
    }
    return temp;
}


int main(void){
    int s = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<TSP(0, 1)<<endl;
    return 0;
}