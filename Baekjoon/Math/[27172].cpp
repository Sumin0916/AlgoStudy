#include<bits/stdc++.h>
using namespace std;

int N;
int arr[100010];
int is_exist[1000010];
int res[1000010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        is_exist[arr[i]] = 1;
    }
    for(int i=0; i<N; i++){
        for(int j=2*arr[i]; j<=1000000; j+=arr[i]){
            if(is_exist[j]){
                res[j]--;
                res[arr[i]]++;
            }
        }
    }
    for(int i=0; i<N; i++){
        cout << res[arr[i]] << ' ';
    }
    return 0;
}