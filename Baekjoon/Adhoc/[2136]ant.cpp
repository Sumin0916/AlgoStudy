#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, L;
vector<pair<ll,ll>> A;
ll ML=-1, MR=-1;
int P;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    cin >> N >> L;
    for(int i=1; i<=N; i++){
        ll a; cin >> a;
        if(a<0) {ML=max(ML, -a);P++;}
        else MR=max(MR, L-a);
        A.emplace_back(abs(a), i);
    }
    sort(A.begin(), A.end());
    if(ML>MR) cout << A[P-1].second << ' ' << ML;
    else cout << A[P].second << ' ' << MR;
    return 0;
}