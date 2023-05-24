#include<bits/stdc++.h>
using namespace std;
int n;
int arr[500050];
int ind[500050];
int c[500050];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int num;
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> arr[i]; ind[arr[i]] = i; }
    for (int i = 1; i <= n; i++) {
        int j = ind[i]; if (i == j) continue;
        swap(arr[i], arr[j]);
        ind[arr[i]] = i; ind[arr[j]] = j;
        c[arr[i]] += abs(i - j);
        c[arr[j]] += abs(i - j);
    }

    for (int i = 1; i <= n; i++) cout << c[i] << " ";
}