#include <iostream>
#define MAX_N 200001
#define MAX_LOG_N 19
using namespace std;

int func[MAX_N];
int sparse_table[MAX_LOG_N][MAX_N];

int main(void){
    int temp, n, x, q, m;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m;
    for (int i = 1; i <= m; i++){
        cin>>temp;
        func[i] = temp;
    }
    for (int i = 1; i < MAX_N; i++){
        sparse_table[0][i] = func[i];
    }
    for (int i = 1; i < MAX_LOG_N; i++){
        for (int j = 1; j < MAX_N; j++){
                temp = sparse_table[i-1][j];
                sparse_table[i][j] = sparse_table[i-1][temp];
        }
    }
    cin>>q;
    for (int i = 0; i < q; i++){
        cin>>n>>x;
        for (int i =  MAX_LOG_N; 0 <= i; --i){
            if (n & (1<<i)){
                x = sparse_table[i][x];
            }
        }
        cout<<x<<'\n';
    }
    return 0;
}