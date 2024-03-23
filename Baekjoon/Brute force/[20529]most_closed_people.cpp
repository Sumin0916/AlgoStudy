#include<bits/stdc++.h>

using namespace std;

int T;
int ans=99;
map<string, int> M;
typedef vector<string> VEC;

int diff(string a, string b){
    int c=0;
    for(int i=0; i<4; i++)if(a[i]!=b[i])++c;
    return c;
}

void combi(auto m_iter, int step, VEC dis) {
    if (ans == 0) return;
    if (step == 3) { 
        ans=min(diff(dis[0], dis[1])+diff(dis[0], dis[2])+diff(dis[1], dis[2]),ans); 
        return;
    }
    for (auto now_iter=m_iter; now_iter != M.end();now_iter++) {
        if ((now_iter->second) >= 1) {
            (now_iter->second)--;
            dis.push_back(now_iter->first);
            combi(now_iter, step+1, dis);
            dis.pop_back();
            (now_iter->second)++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    for(int i=0;i<T;i++){
        int N; cin >> N;
        for(int j=0;j<N;j++){
            string mbti; cin >> mbti;
            M[mbti]++;
        }
        VEC a;
        combi(M.begin(), 0, a);
        cout << ans <<'\n';
        M.clear();
        ans=99;
    }
    return 0;
}