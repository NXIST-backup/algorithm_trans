#include "iostream"
#include "cstring"
using namespace std;

int t;
int n, k, d;

const int N = 105;


int main()
{
    cin >> t;
    while(t--){
        cin >> n >> k >> d;
        bool h[N];
        int f[N];
        for (int i = 1; i <= n;i++)
            cin >> f[i];
        int maxN = 1e9+3;
        for (int i = 1; i <= n - d+1;i++)
        {
            int cnt = 0;
            memset(h, 1, sizeof h);
            for (int j = i; j < i+d;j++)
            {
                if(h[f[j]])
                {
                    h[f[j]] = 0;
                    cnt++;
                }
            }
            if(maxN>=cnt)
                maxN = cnt;
        }
        cout << maxN << endl;
    }
}
