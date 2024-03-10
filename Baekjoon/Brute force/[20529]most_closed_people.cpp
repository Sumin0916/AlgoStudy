#include<iostream>
#include<string>
#include<map>

using namespace std;

int T;
int ans=99;
map<string, int> M;

void combi(auto m_iter, int step, int dis) {
    if (step == 3) { ans=min(dis,ans); return; }
    for (auto now_iter=++m_iter; now_iter != M.end();now_iter++) {
        if ((now_iter->second)>1) {
            --now_iter->second;
            combi(now_iter, step+1, dis);
            ++now_iter->second;
        }
        else {
            combi(now_iter, step+1, dis)
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
        for(auto iter=M.begin();iter!=M.end();iter++){
        cout << iter->first << ' ' << iter->second << ' ';
        }
        cout << ans <<'\n';
        M.clear();
        ans=99;
    }
    return 0;
}