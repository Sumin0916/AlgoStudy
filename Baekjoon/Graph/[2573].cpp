#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[303][303];

bool is_sep(){
    int temp[303][303];
    int land=0;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) temp[i][j] = (arr[i][j] != 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] != 0){
                bfs(temp, i, j);
                land++;
            }
        }
    }
    if(land >= 2) return true;
    return false;
}

void bfs(int temp[][303], int x, int y){
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    temp[x][y] = 1;
    while(!Q.empty()){
        pair<int, int> now = Q.front();
        Q.pop();
        if(now.first+1 < N && temp[now.first+1][now.second] == 0) {Q.push(make_pair(now.first+1, now.second));temp[now.first+1][now.second]=1;}
        else if(now.first-1 >= 0 && temp[now.first-1][now.second] == 0) {Q.push(make_pair(now.first-1, now.second));temp[now.first-1][now.second]=1;}
        else if(now.second+1 < N && temp[now.first][now.second+1] == 0) {Q.push(make_pair(now.first, now.second+1));temp[now.first][now.second+1]=1;}
        else if(now.second-1 >= 0 && temp[now.first][now.second-1] == 0) {Q.push(make_pair(now.first, now.second-1));temp[now.first][now.second-1]=1;}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    int T = 0;
    while(!is_sep()){
        
    }
    return 0;
}