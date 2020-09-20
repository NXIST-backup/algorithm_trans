#include "iostream"
#include "algorithm"
using namespace std;

int q;
int n;
int a[105];

int main()
{
    cin >> q;
    while(q--){
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];

        sort(a, a + n);
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i]+1 == a[i + 1]&&i!=n-1)
                flag = 1;
        }
        if(flag)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}
