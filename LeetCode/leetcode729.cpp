#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

class MyCalendar
{
  public:
    vector<pair<int, int>> list;
    MyCalendar()
    {
        list.clear();
    }

    bool book(int start, int end)
    {
        bool flag = true;
        for (int i = 0; i < list.size(); i++) {
            int l = list[i].first, r = list[i].second;
            if (start >= r || end <= l)
                continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            list.push_back({start, end});

        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
