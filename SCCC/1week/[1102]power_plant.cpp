#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
int graph[17][17];

int main(void){
    int temp, least_on;
    int start_bit = 0;
    queue<pair<int, int>> q;
    string stat;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin>>temp;
            graph[i][j] = temp;
        }
    }
    cin>>stat;
    for (int i = 0; i < N; i++){
        if (stat[i] == 'Y'){
            start_bit |= (1<<(i+1));
            //q.push(make_pair())
        }
    }
    cin>>least_on;
    return 0;
}