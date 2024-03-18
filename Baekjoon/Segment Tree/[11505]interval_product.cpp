#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll N, M, K;
ll tree[1<<22];
ll arr[1000100];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    return tree[node] = (init(start, (start+end)/2, node*2) * init((start+end)/2+1, end, node*2+1))%MOD;
}

ll update(int idx, ll val, int start, int end, int node){
    if(idx > end || idx < start) return tree[node];
    if(start == end) return tree[node] = val;
    return tree[node] = (update(idx, val, start, (start+end)/2, node*2) * update(idx, val, (start+end)/2+1, end, node*2+1))%MOD;
}

ll query(int start, int end, int left, int right, int node){
    if(start > right || end < left) return 1;
    if(left <= start && end <= right) return tree[node];
    return (query(start, (start+end)/2, left, right, node*2)*query((start+end)/2+1, end, left, right, node*2+1))%MOD;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K; int I=M+K;
    for(int i=1; i<=N; i++) cin >> arr[i];
    init(1, N, 1);    
    while(I--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1) {update(b, c, 1, N, 1);}
        else cout << query(1, N, b, c, 1) << '\n';
    }
}