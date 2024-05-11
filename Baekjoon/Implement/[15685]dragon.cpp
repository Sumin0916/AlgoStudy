#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef vector<pair<int, int>> VP;

int grid[101][101];
int N, x, y, d, g, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void NG(VP *V){
    int VN = V->size();
    P std = V->back();
    for(int i=1; i<VN-1; i++) V->push_back(make_pair((*V)[i].second-std.second + std.first, -((*V)[i].first-std.first) + std.second));
    V->push_back(make_pair((*V)[0].second-std.second + std.first, -((*V)[0].first-std.first) + std.second));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    while(N--){
        cin >> x >> y >> d >> g;
        VP DC; DC.push_back(make_pair(y, x)); DC.push_back(make_pair(y+dy[d], x+dx[d]));
        while(g--) NG(&DC);
        for(auto i=DC.begin(); i!=DC.end(); i++) grid[i->first][i->second] = 1;
    }
    for(int i=0; i<100; i++) for(int j=0; j<100; j++) ans+=grid[i][j]*grid[i+1][j]*grid[i][j+1]*grid[i+1][j+1];
    cout << ans;
    return 0;
}