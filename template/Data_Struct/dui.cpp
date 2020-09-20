//1.插入一个数 heap[++size]=x;up(size);
//2.求集合中的最小值 heap[1]
//3.删除最小值  heap[1]=heap[size];size--;
//4.删除任意一个元素    heap[k]=heap[size];size--;down(k);up(k);
//5.修改任意一个元素 heap[k]=x;down(k);up(k);
//堆是一个完全二叉树

//小根堆

#include "iostream"
using namespace std;

const int N = 100010;

int n, m;
int h[N], size1;

void down(int u)
{
    int t = u;
    if(u*2<=size1&&h[u*2]<h[t])
        t = u * 2;
    if (u * 2 + 1 <= size1&&h[u*2+1]<h[t])
        t = u * 2 + 1;
    if(u!=t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> h[i];
    size1 = n;

    for (int i = n / 2; i;i--)
        down(i);// O(n)建堆法 

    while(m--){//循环去堆头
        cout << h[1] << " ";
        h[1] = h[size1];
        size1--;
        down(1);
    }
}