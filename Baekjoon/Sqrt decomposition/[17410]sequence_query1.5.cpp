#include<bits/stdc++.h>
using namespace std;

int arr[100010];
int N, M, sq;
vector<vector<int>> blk;

void init(){
    sq = 1500;
    blk.resize(sq+10);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        blk[i/sq].push_back(arr[i]);
    }
    for(int i=0;i<N/sq+1;i++) sort(blk[i].begin(), blk[i].end());
}

void update(int i, int k){
    auto it = lower_bound(blk[i/sq].begin(), blk[i/sq].end(), arr[i]);
    blk[i/sq].erase(it);
    if(arr[i]<=k) blk[i/sq].insert(lower_bound(it, blk[i/sq].end(), k), k);
    else blk[i/sq].insert(lower_bound(blk[i/sq].begin(), it, k), k);
    arr[i] = k;
}

void query(int i, int j, int k){
    int cnt=0;
    while(i%sq && i <= j)cnt += (arr[i++] > k);
    while((j+1)%sq && i <= j)cnt += (arr[j--] > k);
    while(i <= j){
        cnt += blk[i/sq].end() - upper_bound(blk[i/sq].begin(), blk[i/sq].end(), k);
        i += sq;
    }
    cout<< cnt << '\n';
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    init();
    cin >> M;
    while(M--){
        int op, a, b, c;
        cin >> op >> a >> b;
        if(op == 2){
            cin >> c;
            query(a, b, c);
        }
        else update(a, b);
    }
}