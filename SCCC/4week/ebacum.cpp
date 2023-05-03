#include<iostream>
#include<math.h>

using namespace std;
typedef long long int ll;

int n, m, sq, k;
ll array[10101010];
ll blk[10101] = {0,};

void init(){
    sq = sqrt(n);
    for (int i = 1; i <= n; i++) {
        int bid = i/sq;
        blk[bid] += array[i];
    }
}

void update(int l, int r, ll val) {
    for (int i = l; i <= r; i++){
        array[i] += val;
        blk[i/sq] += val;
    }
}

ll query(int l, int r){
    ll res = 0;
    while((l%sq != 0) && l <= r){res += array[l++];}
    while(((r+1)%sq != 0) && l <= r){res += array[r--];}
    while(l <= r){
        res += blk[l/sq];
        l += sq;
    }   
    return res;
}

void pary(int l, int r, ll *arr){
    for (int i = l; i <= r; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> array[i];
    }
    init();
    for (int i = 0; i < m+k; i++){
        int a, b, c, d; cin >> a;
        if (a==2){
            cin >> b >> c >> d;
            update(b, c, d);
            //pary(1, n, array);
            //pary(0, sq, blk);
        }
        else{
            cin >> b >> c;
            cout << query(b,c) << '\n';
        }
    }
    return 0;
}
