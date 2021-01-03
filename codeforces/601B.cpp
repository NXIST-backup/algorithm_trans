#include "iostream"
#include "algorithm"
#include "cstring"
#include <vector>
using namespace std;

int t, n, m;

const int N = 10050;


int main()
{
    int s[N];
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n;i++)
        {
            int x;
            cin >> x;
            sum += x * 2;
        }
        for (int i = 1; i <= n;i++)
            s[i] = 2;
        if (m < n||n<=2)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << sum << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <=n; j++)
                {
                    if(i!=j&&s[j]==2)
                    {
                        cout << i << " " << j << endl;
                        s[i]--;
                        s[j]--;
                        break;
                    }
                }
            }
            for (int i = 1; i <= n;i++)
            {

                if(s[i])
                    cout << i << " ";
            }
            cout << endl;
        }
    }
}