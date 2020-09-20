
//食物链(eg.带权并查集)
//带权并查集指的是用另外一组集合去维护树林之间的关系，并通过find函数更新与父节点的权值。
//并查集在此题是用来维护各集合的连通关系
//使用并查集这种数据结构去维护一个树(eg.该树上的点都和父节点连通，这样就能通过与父节点的关系解决任意两点的关系了)
//这样查询的时候时间复杂度就接近O(1)了


#include "iostream"
using namespace std;

int n,m;
int p[50010], d[50010];


int find(int x)
{
	if(p[x]!=x)
	{
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}

int main()
{

	cin >> n >> m;

	for (int i = 1; i <= n;i++)
		p[i] = i;
	int res = 0;

	while(m--){

		int t, x, y;

		cin >> t >> x >> y;

		if(x>n||y>n)
			res++;
		else
		{
			int px = find(x), py = find(y);
			if(t==1)//同类操作 如果非同类 res++ 如果不知道两者状态 则设为同类且合并集合
			{
				if(px==py&&(d[x]-d[y])%3)//d[x]%3!=d[y]%3，在一棵树上
					res++;               //非同类
				else if(px!=py)//合并集合
				{
					p[p[x]] = py;//x的父节点的父节点连到y的父节点上
                    d[px] = d[y] - d[x]; //d[x]%3=d[y]%3
                                         //所以(d[x]-d[y])%3=0
                                         //所以直接取d[x]-d[y] or d[y]-d[x]的值就行了
                }
			}
            else //类似前面 因为只有三只动物所以只需要多加一个-1就可以表示捕食状态了
            {
				if(px==py&&(d[x]-d[y]-1)%3)
					res++;
				else if(px!=py)
				{
					p[px] = py;
					d[px] = d[y] + 1 - d[x];
				}

			}
		}
	}
	cout << res << endl;
}