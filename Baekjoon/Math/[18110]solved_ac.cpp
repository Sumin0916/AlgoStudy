#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    int a = round(n * (0.15));
    sort(arr.begin(), arr.end());
    int sum = accumulate(arr.begin()+a, arr.end()-a, 0);
    if (n != 0) cout << round((double)sum/(n-(2*a)));
    else cout << 0;
    return 0;
}