#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++){
        double res = 1000000;
        int N, L;
        vector<int> v;
        cin >> N >> L;
        v.push_back(0);
        for (int i = 0; i < N; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        
        for (int i = 1; i < N+1; i++){
            v[i] += v[i-1];
        }
        
        for (int i = L; i < N+1; i++){
            for (int j = i; j < N+1; j++){
                double temp;
                temp = (v[j]-v[j-i])/(double)(i);
                res = min(res, temp);
            }
        }
        
        cout << res << "\n";
    }
    return 0;
}