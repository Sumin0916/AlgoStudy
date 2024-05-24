#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, L;
ll I, T;
vector<pair<ll, ll>> ant;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    cin >> N >> L;
    for(int i=1; i<=N; i++){
        ll a; cin >> a;
        if(a<0){
            if(T <= -a){
                T = -a;
            }
            ant.emplace_back(-a-(L/2), i);
        }
        else{
            if(T <= L-a){
                T = L-a;
            }
            ant.emplace_back(L/2-a, i);
        }
    }
    sort(ant.begin(), ant.end());
    cout << ant[ant.size()-1].second << ' ' << T;
    return 0;
}