/*
  Problem Name:Hachi
  algorithm tag:math?
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

bool st[1000];
string s;
vector<int> a;
int state[10];
bool is_valid = false;
void dfs(int depth)
{
    if (a.size() == 3) {
        int sum = a[0] * 100 + a[1] * 10 + a[2];
        if (st[sum])
            is_valid = true;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (state[i]) {
            a.push_back(i);
            state[i]--;
            dfs(depth + 1);
            a.pop_back();
            state[i]++;
        }
        if (is_valid)
            break;
    }
}

int main()
{
    for (int i = 0; i <= 999; i++) {
        if (i % 8 == 0)
            st[i] = 1;
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        state[s[i] - '0']++;
    }
    if (s.size() >= 3)
        dfs(0);
    else {
        if (s.size() == 1) {
            int t = stoi(s);
            if (st[t])
                is_valid = true;
        } else {
            int t = stoi(s);
            swap(s[1], s[0]);
            int t1 = stoi(s);
            if (st[t] || st[t1])
                is_valid = true;
        }
    }
    if (is_valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}