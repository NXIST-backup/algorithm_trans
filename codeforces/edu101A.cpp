/*
  Problem Name:
  algorithm tag:
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

int t;

string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        if (s[0] == ')') {
            cout << "NO" << endl;
            continue;
        }
        if (s.size() % 2) {
            cout << "NO" << endl;
            continue;
        }
        if (s.back() == '(') {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}