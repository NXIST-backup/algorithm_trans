#include "algorithm"
#include "iostream"
using namespace std;

int q;
int n;
string a[55];
int b[55];
int c1,c0;
int main()
{
    cin >> q;
    while(q--){

        cin >> n;

        for (int i = 0; i < n;i++)
            cin >> a[i];

        for (int i = 0; i < n;i++)
            b[i] = a[i].size();

        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < b[i];j++)
            if(a[i][j]==0)
                c0++;
            else
                c1++;
        }
        sort(b, b + n);
        for (int i = 0; i < n;i++)
        {
            if(b[i]%2)
            {
                if()
            }
        }
    }
}









