//合并果子

#include <functional>
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
const int INF = 1e9;
typedef pair<int, int> pii;

int n;
priority_queue<int, vector<int>, greater<int>> heap;


int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
    }
    int cost = 0;
    while(heap.size()!=1){
        int l, r;
        l = heap.top();
        heap.pop();
        r = heap.top();
        heap.pop();
        cost += l + r;
        heap.push(l + r);
    }

    cout << cost << endl;
}