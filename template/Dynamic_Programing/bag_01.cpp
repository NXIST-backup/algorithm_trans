//
//               集合(符合条件的所有选法的表示)
//              /
//       状态表示  
//      /       \
// y式DP         属性-key(Max,min,num)
//      \
//       状态计算——集合划分
//
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

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n;i++)
        for (int j =m; j >= v[i];j--)
        {

            //f[i][j]=f[i-1][j]去掉了原因是可以用滚动数组替代，当i迭代上一个f[i-1][j]会同等与下一个f[i][j]
            f[j] = max(f[j], f[j - v[i]] + w[i]);//推f[i][j]之前要推出f[i-1][j]和f[i-1][j-vi]
                                                //如果是顺序的话f[i-1][j-vi]会在i的时候被f[i][j-vi]替换
                                                //因为j-vi肯定小于j
                                                //所以需要倒序
        }

    cout << f[m] << endl;
}

