//(2)分解质因数
//  试除法O(sqrt(N))
//  !每个合数都能分解成几个质数相乘

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

//n中最多只包含一个大于sqrt(n)的质因子
//如果出现两个，相乘就超过n了

int n;
vector<int> a;


void devide(int n)
{
    for (int i = 2; i <= n / i;i++)
        if(n%i==0)
        {
            int s = 0;
            while(n%i==0)
            {
                n /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    if(n>1)
        cout << n << " " << 1 << endl;
}



int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (auto item:a)
    {
        devide(item);
        cout << endl;
    }

}