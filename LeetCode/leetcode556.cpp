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
bool cmp(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
class Solution
{
  public:
    int nextGreaterElement(int n)
    {
        vector<int> num;
        while (n) {
            num.push_back(n % 10);
            n /= 10;
        }
        int res = 0;
        bool flag = false;
        int mi[10];
        for (int i = 0; i < 10; i++)
            mi[i] = 11;
        for (int i = 0; i < num.size(); i++)
            mi[num[i]] = min(i, mi[num[i]]);
        for (int i = 1; i < num.size(); i++) {
            for (int j = num[i] + 1; j < 10; j++)
                if (mi[j] != 11 && mi[j] < i) {
                    swap(num[i], num[mi[j]]);
                    sort(num.begin(), num.begin() + i, cmp);
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }
        long long ans = 0;
        for (int i = 0; i < num.size(); i++)
            ans += pow(10, i) * num[i];
        return ans <= INT32_MAX && flag ? ans : -1;
    }
};

int main()
{
    Solution s;
    cout << s.nextGreaterElement(230241) << endl;
}
