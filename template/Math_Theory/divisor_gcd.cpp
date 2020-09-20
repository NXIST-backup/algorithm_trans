//最大公约数
//辗转相除法
//定理1：d|a,d|b <——> d|(ax+by) eg.整除不是整除以
//d_m(a,b)=d_m(b,a mod b) 
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

int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;

    while (n--) {

        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}
