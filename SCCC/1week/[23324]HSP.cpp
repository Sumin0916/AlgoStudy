#include <iostream>
#define MAX 100001

using namespace std;
using ll = long long;

int parent[MAX];
int count[MAX] = {0, };
ll res = 1;

int find_parent(int node){
    if (parent[node] == node){return node;}
    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b){
    a = find_parent(a); b = find_parent(b);
    if (a > b){
        count[b] += count[a]; count[a] = 0;
        parent[a] = b;
        return;
    }
    else {
        count[a] += count[b]; count[b] = 0;
        parent[b] = a;
        return;
    }
}

void init_array(){
    for (int i = 0; i < MAX; i++){parent[i] = i;}
    for (int i = 0; i < MAX; i++){count[i] = 1;}
    return;
}

int main(void){
    int n, m, k;
    int s, e;
    int cnt = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    init_array();
    cin>>n>>m>>k;

    for (int i = 1; i <= m; i++){
        cin>>s>>e;
        if (i==k){continue;}
        if (find_parent(s) != find_parent(e)){union_parent(s,e);}
    }

    for (int i = 1; i <= n; i++){
        if (count[i] == 0){continue;}
        cnt += 1;
        res *= count[i];
    }
    if (cnt < 2){cout<<0;}
    else {cout<<res;}
    return 0;
}