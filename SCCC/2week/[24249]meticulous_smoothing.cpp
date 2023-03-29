#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    int result = 987654321, plank[1000001];
    cin>>N;
    for (int i = 0; i < N; i++){cin>>plank[i];}
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(0, 1, 0));
    while(!Q.empty()){
        tuple<int, int, int> info;
        info = Q.front(); Q.pop();
        int index = get<0>(info);
        int now_len = plank[index];
        int lenth = get<1>(info);
        int count = get<2>(info);
        if (index == N-1){result = min(result, count);continue;}
        Q.push(make_tuple(index+1, ));
        Q.push(make_tuple(index+1, , ));
    }
    return 0;
}