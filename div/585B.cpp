#include "iostream"
#define ll long long
using namespace std;
int n;
ll sum[2],ans[2];
int main(){
    cin>>n;
    int now=0;
    for(int i=1;i<=n;++i){
        sum[now]++;
        int x;
        scanf("%d",&x);
        if(x<0)now^=1;
        ans[0]+=sum[now];
        ans[1]+=sum[now^1];
	}
	cout<<ans[1]<<' '<<ans[0]<<endl;
}