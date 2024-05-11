#include<bits/stdc++.h>
using namespace std;
const int OFF = -987654321;
int N, W, T, K, ans;
int F[6];
deque<pair<pair<int, int>, vector<int>>> Q;

int alive_fire(vector<int> &A){
    int f=0;
    for(int i=0; i<N; i++){
        if(A[i] > 0) f++;
    }
    return f;
}

vector<int> loss_fire(vector<int> &A){
    vector<int> B(7);
    B[0] = A[0] - (3-(A[1]>0));
    for(int i=1; i<N-1; i++){
        B[i] = A[i] - (3-(A[i-1]>0) - (A[i+1]>0));
    }
    B[N-1] = A[N-1] - (3-(A[N-2]>0));
    return B;
}

vector<int> added_wood_fire(vector<int> &A, int w){
    vector<int> res(7);
    for(int i=0; i<N; i++){
        res[i] = A[i];
    }
    if(A[w] <= 0) return res;
    if(w==0) res[w] += (3-(A[1]>0));
    else if(w==N-1) res[w] += (3-(A[w-1]>0));
    else res[w] += (3-(A[w-1]>0)-(A[w+1]>0));
    return res;
}

int main(){
    cin >> N >> W >> T >> K;
    vector<int> SF(7);
    for(int i=0; i<N; i++){ int t; cin >> t; SF[i] = t; }
    Q.emplace_back(make_pair(T-1, W), SF);
    while(!Q.empty()){
        int now_t = Q.front().first.first;
        int now_w = Q.front().first.second;
        vector<int> now_fire = Q.front().second;
        Q.pop_front();
        now_fire = loss_fire(now_fire);
        if(alive_fire(now_fire) < K) continue;
        if(now_t == 0) {ans++; continue;}
        if(now_w-1 >= 0) {
            Q.emplace_back(make_pair(now_t-1, now_w-1), added_wood_fire(now_fire, now_w-1));
        }
        if(now_w+1 < N) {
            Q.emplace_back(make_pair(now_t-1, now_w+1), added_wood_fire(now_fire, now_w+1));
        }
        Q.emplace_back(make_pair(now_t-1, now_w), added_wood_fire(now_fire, now_w));
    }
    cout << ans;
    return 0;
}