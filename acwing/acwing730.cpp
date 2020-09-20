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

using namespace std;

const int N=1e5+50;

ll h[N];
int n;
bool flag=1;
int bs(int l,int r)
{
    if(l>=r)
        return l;
    int mid=l+r>>1;
    flag = 1;
    ll cost = mid;
    for(int i=1;i<=n;i++){
        if(cost<0){
            flag=0;
            break;
        }
        if(cost>=h[i]){
            if(cost<1e5)
                cost+=cost-h[i];
            else{
                flag = 1;
                break;
            }
        }
        else{
            cost-=h[i]-cost;
        }
    }
    
    if(flag)
        bs(l,mid);
    else
        bs(mid+1,r);

}


int main()
{
    cin>>n;
    h[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    int ans=bs(0,1e5);
    
    cout<<ans<<endl;
}