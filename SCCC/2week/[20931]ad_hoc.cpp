#include<iostream>
#include<bitset>
#define MAX_LOG_L 61
#define MAX_QUERY 150001
using namespace std;

int sparse_table[MAX_LOG_L][MAX_QUERY];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bitset<61> bitl;
    int Q, x, k, last_ans = 0;
    sparse_table[0][0] = 0;
    long long L;
    string query;
    bitl.reset();
    cin>>Q;
    for (int i = 0; i < Q; i++){
        cin>>query;
        if (query == "ad-hoc"){
            cin>>x>>L;
            
        }
        else {cin>>k>>L;}

    }
    return 0;
}