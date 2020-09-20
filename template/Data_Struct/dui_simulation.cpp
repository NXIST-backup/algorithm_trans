//1.插入一个数 heap[++size]=x;up(size);
//2.求集合中的最小值 heap[1]
//3.删除最小值  heap[1]=heap[size];size--;
//4.删除任意一个元素    heap[k]=heap[size];size--;down(k);up(k);
//5.修改任意一个元素 heap[k]=x;down(k);up(k);
//堆是一个完全二叉树

//小根堆

#include "iostream"
#include "algorithm"
#include <cstring>
using namespace std;

const int N = 100010;

int h[N], ph[N],hp[N],size1;

void heap_swap(int a,int b)
{
    
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);

}



void down(int u)
{
    int t = u;
    if(u*2<=size1&&h[u*2]<h[t])
        t = u * 2;
    if (u * 2 + 1 <= size1&&h[u*2+1]<h[t])
        t = u * 2 + 1;
    if(u!=t)
    {
        heap_swap(h[u], h[t]);
        down(t);
    }
}
void up(int u)
{
    while(u/2&&h[u/2]>h[u]){
        heap_swap(u / 2, u);
        u /= 2;
    }
}


int main()
{
    int n;
    int m=0;
    cin >> n;
    while(n--){

        char op[10];
        cin >> op;

        int k, x;

        if(!strcmp(op,"I"))
        {
            cin >> x;
            size1++;
            m++;//第几个加入的
            ph[m] = size1, hp[size1] = m;
            h[size1] = x;
            up(size1);
        }

        else if(!strcmp(op,"PM"))
            cout << h[1] << endl;
        else if (!strcmp(op,"DM")) {
            heap_swap(1, size1);
            size1--;
            down(1);
        }
        else if(!strcmp(op, "D"))
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, size1);
            size1--;
            down(k), up(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }   
}