#include "iostream"
#include "vector"
using namespace std;
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a;
        int b[105];
        int flag = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
                a.push_back(b[i]);
        }
        int t = n;
        for (int i = 0; i < t;i++)
        {
            if(a[i]==2048)
            {
                flag = 1;
                break;
            }
            for (int j = 0; j < t;j++)
            {
                if(a[i]==a[j]&&i!=j&&a[i]!=0&&a[j]!=0)
                {
                    a.push_back(a[j] * 2);
                    a[i] = 0;
                    a[j] = 0;
                    t++;
                    break;
                }    
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}