#include<iostream>
#include<vector>
using namespace std;
const int N=35;
int a[N][N];
bool vis[N][N];
bool vis2[N][N];
int n;
vector<pair<int,int>> lr;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		if(!vis[x+dx[i]][y+dy[i]]&&a[x+dx[i]][y+dy[i]]!=1&&x+dx[i]>=0&&y+dy[i]>=0&&x+dx[i]<=n-1&&y+dy[i]<=n-1)
		{
			vis2[x+dx[i]][y+dy[i]]=1;
			vis[x+dx[i]][y+dy[i]]=1;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}



int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	for(int i=0;i<n;i++)
	{
		if(!a[i][0])
			lr.push_back({i,0});
		if(!a[i][n-1])
			lr.push_back({i,n-1});
	}
	for(int j=0;j<n;j++)
	{
		if(!a[0][j])
			lr.push_back({0,j});
		if(!a[n-1][j])
			lr.push_back({n-1,j});
	}
	for(auto item:lr)
	{
// 		cout<<item.first<<" "<<item.second<<endl;
		if(!vis2[item.first][item.second])
			dfs(item.first,item.second);
	}
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<n;j++)
// 			cout<<vis2[i][j]<<" ";
// 		cout<<endl;
// 	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!vis2[i][j]&&a[i][j]==0)
			cout<<2<<" ";
			else
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}