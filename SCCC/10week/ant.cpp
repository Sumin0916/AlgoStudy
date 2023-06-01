#include<bits/stdc++.h>
using namespace std;

map<string, int> trie[1505];
int n, cnt;
int count[1505];

int main() {
    cin.tie(nullptr);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        int cur = 0;

        for (int j = 1; j <= k; j++) {
            string s; cin >> s;
            if (!trie[cur][s]) {
                trie[cur][s] = ++cnt;
            }
            cur = trie[cur][s];
        }

    }
}