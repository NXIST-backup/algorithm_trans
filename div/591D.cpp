#include "iostream"
#include "algorithm"
using namespace std;
int q;
int a[300050];
int n;
int main()
{
    cin >> q;
    while(q--){
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        sort(a, a + n);
        int cnt = 0;
        for (int i = 0; i < n-1;i++)
        {
            if(a[i]!=a[i+1])
                cnt++;
        }
        
    }
}