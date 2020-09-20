//euler函数
//phi(n) 1~n中与n互质的数(eg.互质是公约数只有1的两个整数，叫做互质整数。)
//n=p1^a2*p2^a2...pk^ak;
//phi(n)=n(1-1/p1)(1-1/p2)...(1-1/pk);
//证明（容斥原理）

//1.从1~n中去掉p1,p2,...pk所有的倍数        n-n/p1-n/p2...-n/pk
//2.加上所有pi*pj的倍数                       +n/p1p2+n/p1p3+...
//3.减去所有pi*pj*pk的倍数                    -n/p1p2p3-n/p1p2p4...
//...规律                                    +n/p1p2p3p4+n/p1p2p3p5.......

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

int main()
{
    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        int res = a;
        for (int i = 2; i <= a / i;i++)
        {
            if(a%i==0)
            {
                res = res / i * (i - 1);
                while (a%i==0) {
                    a /= i;
                }
            }   
        }
        if(a>1)
            res = res / a * (a - 1);

        cout << res << endl;
    }
}
