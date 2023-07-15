#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, K;
int dp[4];

vector<int> pull(vector<int> &arr, int a) {
    vector<int> res(N);
    for(int i = 0; i < N-1; i++) res[i] = arr[i];
    for(int i = a; i < N-1; i++) res[i] = arr[i+1];
    return res;
}

vector<int> push(vector<int> &arr, int a) {
    vector<int> res(N);
    for(int i = 0; i < N-1; i++) res[i] = arr[i];
    for(int i = N-1; i > a; i--) res[i] = arr[i-1];
    return res;
}

int findsol(vector<int> &arr1, vector<int> &arr2) {
    int res = 0;
    for(int i = 0; i < N; i++) {if(arr1[i]==arr2[i])res+=1;}
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    vector<int> solution(N);
    vector<int> arr(N);
    queue<pair<vector<int>, int> > q;
    for(int i = 0; i < N; i++) cin >> solution[i];
    for(int i = 0; i < N; i++) cin >> arr[i];
    dp[0] = findsol(solution, arr);
    q.push(make_pair(arr, 0));
    while(!q.empty()) {
        pair<vector<int>, int> nowp = q.front();
        vector<int> now = nowp.first;
        int step = nowp.second;
        q.pop();
        for(int i = 0; i < N; i++) {
            vector<int> arr1 = pull(now, i);
            vector<int> arr2 = push(now, i);
            if (findsol(arr1, solution) >= dp[step+1]) q.push(make_pair(arr1, step+1));
            if (findsol(arr2, solution) >= dp[step+1]) q.push(make_pair(arr2, step+1));
        }
    }
    cout << dp[K];
    return 0;
}