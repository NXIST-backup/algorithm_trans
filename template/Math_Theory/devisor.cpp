//试除法求约数

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

vector<int> get_divisor(int n)
{
    vector<int> res;

    for (int i = 1; i <= n/i;i++)
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=n/i)
                res.push_back(n / i);
        }
    sort(res.begin(), res.end());//int范围约数最多有1600多个
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        auto res = get_divisor(x);
        for(auto item:res)
            cout << item << " ";
        cout << endl;
    }
}