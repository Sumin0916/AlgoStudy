#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n, cn, s, e;
int res=0, cnt=0;
vector<pair<int, bool>> cls;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>cn>>s>>e;
        cls.push_back({s, true});
        cls.push_back({e, false});
    }
    sort(cls.begin(), cls.end());

    for (pair<int,bool> &t: cls){
        if (t.second){cnt++;}
        else{cnt--;}
        res = max(res,cnt);
    }
    cout<<res;
    return 0;
}