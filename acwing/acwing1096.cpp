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

const int N=1e2+5;
int l,r,c;
char g[N][N][N];
int dx[6]={0,1,0,-1,0,0};
int dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,-1,1};
string tmp;
int st[N][N][N];


struct Three
{
    int x,y,z;
};
void bfs(int x1,int y1,int z1)
{
    memset(st,0,sizeof st);
    queue<Three> q;
    q.push({x1,y1,z1});
    st[x1][y1][z1]=1;
    while(q.size()){
        
        auto t=q.front();
        q.pop();

        for(int i=0;i<6;i++){
            
            int x=t.x+dx[i],y=t.y+dy[i],z=t.z+dz[i];
            
            if(x<1||x>l||y<1||y>r||z<1||z>c)
                continue;
            if(g[x][y][z]=='#'||st[x][y][z])
                continue;
                
            q.push({x,y,z});
            st[x][y][z]+=st[t.x][t.y][t.z]+1;
        }
    }
}


int main()
{
    while(cin>>l>>r>>c,l&&r&&c){
        
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                for (int k = 1; k <= c; k++)
                    cin >> g[i][j][k];
            }
        }

        int x1,y1,z1;
        int x2,y2,z2;

        for(int i=1;i<=l;i++)
            for(int j=1;j<=r;j++)
                for(int k=1;k<=c;k++){
                    if(g[i][j][k]=='S')
                        x1=i,y1=j,z1=k;
                    else if(g[i][j][k]=='E')
                        x2=i,y2=j,z2=k;
                }
        bfs(x1,y1,z1);
        if(st[x2][y2][z2])
            cout<<"Escaped in "<<st[x2][y2][z2]-1<<" minute(s)."<<endl;
        else
            cout << "Trapped!" << endl;
    }
}