#include "iostream"
using namespace std;
long long  fff(long long  n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return 3 * fff(n - 1)%998244353 + 2 * fff(n - 2)%998244353;
}
int main()
{
    printf("%lld", fff(473844410));
}