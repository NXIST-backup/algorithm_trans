//扩展欧几里得算法
//裴蜀定理
// 对于任意正整数a，b，那么一定存在非0整数x，y，使得ax+by=gcd(a,b)

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
//推导过程
// a*x1+b*y1=gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// b*x2+(a%b)*y2=gcd(a,b)
// a%b=a-a/b*b
// b*x2+(a-a/b*b)*y2=a*x1+b*y1
// a*y2+(x2-a/b*y2)*b=a*x1+b*y1
// x1=y2
// y1=(x2-a/b*y2)
int exgcd(int a, int b, int &x1, int &y1)
{
    if (!b) {
        x1 = 1, y1 = 0;
        return a;
    }
    int x2, y2;
    int d = exgcd(b, a % b, x2, y2);
    x1 = y2, y1 = x2 - (a / b) * y2;
    return d;
}

int main()
{
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        int x1, y1;
        exgcd(a, b, x1, y1);
        cout << x1 << " " << y1 << endl;
    }
}