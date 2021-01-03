/*
  Problem Name:Non-Substring Subsequence
  algorithm tag:implement
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int,int> pii;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, n, Q; string s;
        cin >> n >> Q >> s;
        while(Q--) {
            int l, r; cin >> l >> r; --l; --r;
            bool bad = true;
            for(i = 0; i < l and bad; i++)
                if(s[i] == s[l]) bad = false;
            for(i = r+1; i < n and bad; i++)
                if(s[i] == s[r]) bad = false;
            cout << (bad? "NO" : "YES") << '\n';
        }
    }
    return 0;
}