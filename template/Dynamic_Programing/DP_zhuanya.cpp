//蒙德里安的梦想

//状态压缩DP


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

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 12, M = 1 << N;

int n, m;
ll f[N][M];
vector<int> state[M];
bool st[M];

//思考过程
//1.先放1x2矩形，则剩下的2x1矩形就确定了
//2.f[i][j]可以表示为第i列的1x2矩形的摆放方法的状态(j用二进制表示状态)
//3.预处理符合的状态数
//4.DP

int main()
{   

    while (cin>>n>>m,n||m) {

        for (int i = 0; i < 1 << n;i++)//预处理每列不同状态是否可以插入2x1矩形
        {
            int cnt = 0;//计算0的个数即空行个数
            bool flag=true;
            for (int j = 0; j < n;j++)//逐位计算
                if(i>>j&1)
                {
                    if(cnt%2)
                    {
                        flag=false;
                        break;   
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            if(cnt%2)
                flag=false;
            st[i]=flag;
            

        }

        for (int i = 0; i < 1 << n;i++)//求出f[i-1][state]的状态数
        {
            state[i].clear();
            for (int j = 0; j < 1 << n;j++)
            {
                if((i&j)==0&&st[i|j])
                    state[i].push_back(j);
            }
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;

        for (int i = 1; i <= m;i++)
        {
            for (int j = 0; j < 1 << n;j++)
                for(auto k:state[j])
                {
                    f[i][j] += f[i-1][k];
                }
        }
        cout << f[m][0] << endl;
    }
}