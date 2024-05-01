#include<bits/stdc++.h>
using namespace std;

int N, M;
int ans;
int G[41][41];

struct TRI {
    int cost;
    int point[41];   
};

bool comp(TRI a, TRI b){ return a.cost < b.cost; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<TRI> triangles;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b; G[a][b] = G[b][a] = 1;
    }
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            for(int k=j+1; k<=N; k++){
                TRI A; A.point[i] = A.point[j] = A.point[k] = 1;
                int T = G[i][j]+G[j][k]+G[i][k];
                switch(T){
                    case 3: continue; break;
                    case 2: A.cost = 0; break;
                    case 1: A.cost = 1; break;
                    case 0: A.cost = 2; break;
                }
                triangles.push_back(A);
            }
        }
    }

    while(!triangles.empty()){
        bool flag = false;
        sort(triangles.begin(), triangles.end(), comp);
        for(auto T = triangles.begin(); T != triangles.end(); T++){
            T->cost -= 1;
            T-
        }
    }
    cout << ans;
}