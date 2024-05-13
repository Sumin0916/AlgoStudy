#include<bits/stdc++.h>
using namespace std;

int N, A=0;
vector<pair<int, int>> VP;
priority_queue<int, vector<int>, greater<>> ET;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++){
        int s, t; cin >> s >> t;
        VP.emplace_back(s, t);
    }
    sort(VP.begin(), VP.end());
    for(int i=0; i<N; i++){
        ET.push(VP[i].second);
        if(VP[i].first >= ET.top()) ET.pop();
    }
    cout << ET.size();
    return 0;
}