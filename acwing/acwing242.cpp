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


const int N=1e5+50;

int n,m;
int a[N],b[N];
int tr[N];

int lowbit(int x)
{
    return x & -x;
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tr[i]+=v;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tr[i];
    return res;
}


int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    while(m--){
        char c;
        cin>>c;
        if(c=='C'){
            int l,r,val;
            cin>>l>>r>>val;
            b[l]+=val;
            b[r+1]-=val;
            add(l,val);
            add(r+1,-val);
        }
        else{
            int idx;
            cin>>idx;
            long long ans=0;
            ans=a[idx]+query(idx);
            cout<<ans<<endl;
        }
    }
}