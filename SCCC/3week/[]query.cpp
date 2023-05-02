#include<iostream>
#include<math.h>

using namespace std;
const int MAX = 1000000001;
const int MROOT = sqrt(MAX) + 1;
int array[MAX];

int find_min(int i, int j, int arr[]){
    int res = MAX;
    for(int k = i; k <= j; k++){
        res = min(arr[k], res);
    }
    return res;
}

int refresh(int num_blk, int root[]){
    int start = num_blk*MROOT;
    int end = start+MROOT;
    int m = MAX;
    for (int i = start; i < end; i++){
        m = min(m, array[i]);
    }
    root[num_blk] = m;   
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int root_blk[MROOT];
    int N;
    cin>>N;
    for (int i = 0; i < N; i++){int t;cin>>t;array[i]=t;}
    int M;
    cin>>M;
    for (int i = 0; i < MROOT; i++){refresh(i, root_blk);}
    for (int i = 0; i < M; i++){
        int q, a, b;
        cin>>q>>a>>b;
        if (q==1){
            array[a] = b;
            for (int i = 0; i < MROOT; i++){
                if (i <= a && a < i+MROOT){refresh(i, root_blk);}
            }
        }
        else{
            int res;
            for (int i = 0; i < MROOT; i++){
                if (){
                    
                }
            }
            cout<<res;
        }

    }
    return 0;
}