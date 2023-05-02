#include<iostream>
#include<math.h>
#include<memory.h>

using namespace std;

int n, m, sq;
const int INF = 1111111111;
int array[100002];
int blk[10101];

void init(){
    sq = sqrt(n);
    for (int i = 1; i <= n; i++) {
        int bid = i/sq;
        blk[bid] = min(array[i], blk[bid]);
    }
}

void update(int ind, int val) {
    array[ind] = val;
    int blkind = ind/sq;
    int sind = blkind * sq;
    int eind = sind + sq;
    blk[blkind] = INF;
    for (int i = sind; i < eind; i++){blk[blkind] = min(array[i], blk[blkind]);}
}

int query(int l, int r){
    int res = INF;
    while((l%sq != 0) && l <= r){res = min(res, array[l++]);}
    while(((r+1)%sq != 0) && l <= r){res = min(res, array[r--]);}
    while(l <= r){
        res = min(res, blk[l/sq]);
        l += sq;
    }   
    return res;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10101; i++){blk[i]=INF;}
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>array[i];
    }
    init();

    cin>>m;
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        if (a==1)update(b,c);
        else cout << query(b,c) << '\n';
    }
    return 0;
}
