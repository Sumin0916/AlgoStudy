#include <iostream>
#include <vector>

using namespace std;

int N;

struct micro {
        int S;
        int pos;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<micro> line;
    for(int i=1;i<=N;i++){
        int a; cin >> a;
        micro b; b.S=a;b.pos=i;
        line.push_back(b);
    }

    while(1) {
        N = line.size();
        if(N==1) break;
        for(int i=0;i<N;i++) {
            if(!i){ if(line[1].S <= line[0].S) line[0].S += line[1].S; line.erase(line.begin()+1); --N;}
            if(i==(N-1)){ if(line[N-2].S <= line[i].S) line[i].S += line[N-2].S; line.erase(line.begin()+N-2); --N;}
            else{
                if(line[i-1].S <= line[i].S) { line[i].S += line[i-1].S; line.erase(line.begin()+i-1); --N; }
                if(line[i+1].S <= line[i].S) { line[i].S += line[i+1].S; line.erase(line.begin()+i+1); --N; }
            }
        }
    }
    cout << line[0].S << '\n' << line[0].pos;
    return 0;
}