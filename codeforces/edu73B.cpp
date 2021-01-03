#include "iostream"
using namespace std;
typedef long long ll;

int main()
{
    int n;scanf("%d",&n);
    int op;
    for (int i=1;i<=n;i++)
    {
        op=i%2;
        for (int j=1;j<=n;j++)
        {
            op^=1;
            if(op==0) printf("W");
            else printf("B");
        }
        printf("\n");
    }
    return 0;
}