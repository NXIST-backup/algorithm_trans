#include "iostream"
using namespace std;
int main()
{
    int n;
    string a;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int w[100050];
    for (int i = 0; i < n;i++)
        cin >> w[i];
    int min_w=0;
    for (int i = 0; i < n;i++)
    {
        int flag = 0;

        if(a[i]=='w')
        {
            if(flag==0)
            {
                min_w = w[i];
                flag++;
            }
            else if(min_w<=w[i])
            {
                min_w = w[i];
            }
        }
    }
    for (int i = 0; i < n;i++)
    {
        int flag = 0;

        if(a[i]=='r')
        {
            if(flag==0)
            {
                min_r = w[i];
                flag++;
            }
            else if(min_w<=w[i])
            {
                min_r = w[i];
            }
        }
    }
    for (int i = 0; i < n;i++)
    {
        int flag = 0;

        if(a[i]=='o')
        {
            if(flag==0)
            {
                min_o = w[i];
                flag++;
            }
            else if(min_w<=w[i])
            {
                min_o = w[i];
            }
        }
    }
    for (int i = 0; i < n;i++)
    {
        int flag = 0;

        if(a[i]=='n')
        {
            if(flag==0)
            {
                min_n = w[i];
                flag++;
            }
            else if(min_w<=w[i])
            {
                min_n = w[i];
            }
        }
    }
    for (int i = 0; i < n;i++)
    {
        int flag = 0;

        if(a[i]=='g')
        {
            if(flag==0)
            {
                min_g = w[i];
                flag++;
            }
            else if(min_w<=w[i])
            {
                min_g = w[i];
            }
        }
    }
    printf("%d", min_w + min_r + min_o + min_n + min_g);
}