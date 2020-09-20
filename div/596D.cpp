//https://blog.csdn.net/duanghaha/article/details/102772771
//https://baike.baidu.com/item/%E8%B4%A8%E5%9B%A0%E5%AD%90/10720836?fr=aladdin
//完全平方数
#include<iostream>
#include "map"

using namespace std;
const int N = 1e6+100;
long long a[N],b[N];
typedef long long ll;
map<ll,ll> nums;
ll qp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ll now=1;
		ll need=1;
		for(ll j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				int cnt=0;
				while(a[i]%j==0){
					++cnt;
					a[i]/=j;
				}
				cnt%=k;
				now*=qp(j,cnt);
			}
		}
		if(a[i]!=1){
			 now*=a[i];
		}
		a[i]=now;
		nums[a[i]]++;
		for(ll j=2;j*j<=now;j++){
			if(now%j==0){
				int cnt=0;
				while(now%j==0){
					++cnt;
					now/=j;
				}
				need*=qp(j,k-cnt);
			}
		}
		if(now!=1){
			 need*=qp(now,k-1);
		}
		b[i]=need;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]==a[i]){
			ans+=nums[b[i]]-1;
		}else{
			ans+=nums[b[i]];
		}
	}
	cout<<ans/2<<endl;
	return 0;
}
