//就是线性代数

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

const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];

int gauss()
{
    int c, r; //col列row行

    for (c = 0, r = 0; c < n;c++)
    {
        int t = r;
        for (int i = r; i < n;i++)//找到绝对值最大的一行，换到最上方
            if(fabs(a[i][c])>fabs(a[t][c]))
                t = i;
        if(fabs(a[t][c])<eps)//!如果是绝对值最大一行是0的话，直接下一列
            continue;
        for (int i = c; i <= n;i++)//找到后换行
            swap(a[t][i], a[r][i]);
        for (int i = n; i >= c;i--)//把这行所有元素除上第一个元素，总而言之使得第一个元素为1
            a[r][i] /= a[r][c];
        for (int i = r + 1; i < n;i++)//把当前列下面几行变0
            if(fabs(a[i][c])>eps)//非0时
                for (int j = n; j >= c;j--)
                    a[i][j] -= a[r][j] * a[i][c];

        r++;
    }
    if(r<n)
    {
        for (int i = r; i < n;i++)
            if(fabs(a[i][n])>eps)
                return 2;//无解
        return 1;//无穷多组解
    }
    for (int i = n - 1; i >= 0;i--)//多余元素化零
        for (int j = i + 1; j < n;j++)
            a[i][n] -= a[i][j] * a[j][n];
    return 0;//唯一解
}

int main()
{
    cin >> n;

    for (int i = 0; i < n;i++)
        for (int j = 0; j < n + 1;j++)
            cin >> a[i][j];

    int t = gauss();
    if(t==0)
    {
        for (int i = 0; i < n;i++)
            printf("%.2lf\n", a[i][n]);
    }
    else if(t==1)
        cout << "Infinite group solutions" << endl;
    else
        cout << "No solution" << endl;
}