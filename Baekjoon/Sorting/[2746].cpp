#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr;
ll N;
ll TOTAL=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    while(N--){
        ll a; cin >> a; arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    return 0;
}