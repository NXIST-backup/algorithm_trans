//Test 5
#include<cstdio>

using namespace std;
const int MX=20000000;
int *it[MX];
int main(){
	for(int i=0;i<MX;i++)it[i]=new int;
	for(int i=0;i<MX;i++)*it[i]=i;
	int ans=0;
	for(int i=0;i<MX;i++)ans^=*it[i];
	printf("%d\n",ans);
	return 0;
}