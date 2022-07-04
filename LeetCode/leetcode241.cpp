#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

class Solution
{
  public:
    set<int> s;
    vector<int> nums;
    vector<char> ops;
    vector<int> diffWaysToCompute(string expression)
    {
        expression.push_back('/');
        vector<int> ans;
        nums.clear();
        ops.clear();
        s.clear();
        string num;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] >= '0' && expression[i] <= '9')
                num.push_back(expression[i]);
            else {
                nums.push_back(stoi(num));
                if (expression[i] != '/')
                    ops.push_back(expression[i]);
                num.clear();
            }
        }
        for (int i = 0; i < nums.size() - 1; i++)
            s.insert(op(dfs(0, i), dfs(i + 1, nums.size() - 1), ops[i]));
        for (auto item : s)
            ans.push_back(item);
        return ans;
    }
    int dfs(int l, int r)
    {
        static const string &str = "input";
    }
    int op(int a, int b, char c)
    {
        if (c == '+')
            return a + b;
        else if (c == '-')
            return a - b;
        else
            return a * b;
    }
};
