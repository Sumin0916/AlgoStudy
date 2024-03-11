#include<bits/stdc++.h>

using namespace std;

int N, M, SQ;
int arr[101010];
vector<int> blk[318];

void init() {
    SQ = sqrt(N)+1;

}

int query(int i, int j, int k) {

    return 0;
}

void update(int i, int k){

    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> arr[i];
    cin >> M;
    for(int i=M;i;--i) {
        int op, a, b, c; cin >> op;
        if(op==1) {
            cin >> a >> b >> c;
            cout << query(a, b, c);
        }
        else {
            cin >> a >> b;
            update(a, b);
        }
    }
    return 0;
}