#include "iostream"
#include "queue"
#include "map"
#include "cstring"
#include "vector"
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200050;
int n;
bool st[N];
int ma[N];
int st2[N];
int p[N];

int find(int x)
{
    if(p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}
int search(int u)
{
    int temp = 0;
    for (int i = u;;i=ma[i])
    {
        if(st2[i])
        {
            return temp - st2[i]+1;
        }
        else
        {
            st2[i] = temp + 1;
        }
        temp = st2[i];
    }
}

int main()
{
    cin >> n;
    int minn = 1e9 + 10;
    for (int i = 1; i <= n;i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        p[find(i)] = find(x);
        ma[i] = x;
    }
    // for (int i = 1; i <= n;i++)
    // {
    //     cout << find(i) << " ";
    // }
    for (int i = 1; i <= n;i++)
    {
        if(!st[find(i)])
        {
            minn = min(minn, search(find(i)));
            st[find(i)] = true;
        }
    }
    cout << minn << endl;
}
