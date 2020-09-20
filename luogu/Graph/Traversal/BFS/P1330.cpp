#include "iostream"
#include "algorithm"
#include "queue"
#include "cstring"
#include <queue>

using namespace std;

const int N = 1e5+50;

int h[N], e[N], ne[N], idx;
int st[N],st2[N];
int color[N],p[N];
int n, m;
int che;
int cnt[3];
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u)
{
	st[u]=1;
	color[u] = che;
	cnt[che]++;
	//che = (!che);
	for (int i = h[u]; i != -1;i=ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			che = (!color[u]);
			dfs(j);
		}
	}
}
int find(int x)
{
	if(p[x]!=x)
		p[x] = find(p[x]);
	return p[x];
}
int bfs(int u)
{
	queue<int> q;
	q.push(u);
	memset(st, 0, sizeof st);
	while (q.size()) {
		auto t = q.front();
		q.pop();

		for (int i = h[t]; i != -1;i=ne[i])
		{
			int j = e[i];
			if(!st[j])
			{
				if(color[j]==color[t])
					return 0;
				q.push(j);
				st[j] = 1;
			}
		}
	}
	return 1;
}



int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n;i++)
	{
		p[i] = i;
	}
	for (int i = 1; i <= m;i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
		p[find(x)] = find(y);
	}
	int minn = 0;
	int flag = 1;
	for (int i = 1; i <= n;i++)
	{
		if(!st2[find(i)]&&p[i]!=i)
		{
			//cout << "heloo" << endl;
			memset(cnt, 0, sizeof cnt);
			memset(color, -1, sizeof color);
			dfs(p[i]);
			int x = bfs(p[i]);
			if(x)
			{
				minn += min(cnt[0], cnt[1]);
			}
			else
			{
				flag = 0;
				break;
			}
			st2[find(i)] = true;
		}
	}
	if(flag)
		cout << minn << endl;
	else
		cout << "Impossible" << endl;

}