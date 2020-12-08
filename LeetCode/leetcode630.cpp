/*
  Problem Name:课程表Ⅲ  
  algorithm tag:最长上升子序列，贪心
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else
        return false;
}

vector<pii> a;

int main()
{
    for (int i = 1; i <= 8; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(a.begin(), a.end(), cmp);

    int sum = 0;
    priority_queue<int, vector<int>, less<int>> heap;
    int cur = 0;
    int ans = 0;
    for (auto item : a) {
        if (item.first + sum <= item.second) {
            ans++;
            heap.push(item.first);
            sum += item.first;
            cur = item.second;
        } else {
            if (item.second - (sum - heap.top()) - item.first > cur - sum) {
                sum -= heap.top();
                heap.pop();
                sum += item.first;
                cur = item.second;
                heap.push(item.first);
            }
        }
    }
    cout << ans << endl;
}
