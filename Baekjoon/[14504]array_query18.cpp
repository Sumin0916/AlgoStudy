#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int N, M, sq;
int arr[100010];
vector<int> blk [318];

void init() {
    sq = sqrt(N);
    for(int i=1; i<=N; i++) {
        blk[i/sq].push_back(arr[i]);
    }
    for(int i=0; i<=(sq+1); i++) {
        sort(blk[i].begin(), blk[i].end());
    }
}

int query(int i, int j, int k) {
    int cnt=0;
    while((i%sq)!=0 && i<=j) if(arr[i++] > k) cnt++;
    while((j+1%sq)!=0 && i<=j) if(arr[j--] > k) cnt++;
    while(i <= j){
        cnt += blk[i/sq].end() - upper_bound(blk[i/sq].begin(), blk[i/sq].end(), k);
        i+=sq;
    }
    return cnt;
}

// void update(int i, int k) {
//     blk[i/sq].erase(lower_bound(blk[i/sq].begin(), blk[i/sq].end(), arr[i]));
//     blk[i/sq].insert(lower_bound(blk[i/sq].begin(), blk[i/sq].end(), k), k);
//     arr[i] = k;
//     return;
// }

void update(int i, int k) {
    auto it=lower_bound(blk[i/sq].begin(), blk[i/sq].end(), arr[i]);
    arr[i] = k;
    *it = k;
    sort(blk[i/sq].begin(), blk[i/sq].end());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    init();
    cin >> M;
    for(int i=M; i; i--) {
        int op, a, b, c;
        cin >> op;
        if(op == 1) {
            cin >> a >> b >> c;
            cout << query(a, b, c) << '\n';
        }
        else {
            cin >> a >> b;
            update(a, b);
        }
    }
    return 0;
}