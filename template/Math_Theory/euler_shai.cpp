//筛法求欧拉函数O(n)
// φ-phi
//欧拉函数公式：phi(n)=n*(1-1/p1)*(1-1/p2)...*(1-1/pk);
//欧拉定理 若a与n互质 则有a^(phi(n)) == 1 (mod n) 同余
//若p为质数 a^(p-1) == 1(mod p) 费马小定理
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

const int N = 1e6 + 50;
int prime[N];
bool st[N];
int cnt;
int phi[N];
long long get_euler(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n ;i++)
    {
        if(!st[i])
            prime[cnt++] = i,phi[i]=i-1;//质数n的欧拉函数是n-1
        for (int j = 0; prime[j] <= n / i;j++)
        {
            st[prime[j] * i] = true;//不管怎么样pj都是pj*i的最小质因子
            if(i%prime[j]==0)//当pj是i的最小质因子的时候phi(pj*i)=phi(i)*pj
            {
                phi[prime[j] * i] = phi[i]*prime[j];
                break;
            }
            else //当pj不是i的最小质因子时phi(pj*i)=phi[i]*(pj-1)
                phi[prime[j] * i] = phi[i] * (prime[j] - 1);//
        }
    }

    long long res = 0;
    for (int i = 1; i <= n;i++)
        res += phi[i];
    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << get_euler(n) << endl;
}
