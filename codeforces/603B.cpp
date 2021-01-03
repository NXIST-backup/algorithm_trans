#include "iostream"
#include "cstring"
#include "vector"

using namespace std;

int t;
int n;
string p[20];
int num[20];
int st[10000];

int main()
{
    cin >> t;

    while (t--) {

        cin >> n;
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n;i++)
        {
            cin >> p[i];
            num[i] = (p[i][0] - '0') * 1000 + (p[i][1] - '0') * 100 + (p[i][2] - '0') * 10 + (p[i][3] - '0');
            st[num[i]]++;
        }
        int sum = 0;
        for (int i = 0; i < 10000;i++)
        {
            if(st[i]>1)
                sum += st[i] - 1;
        }
        cout << sum << endl;
        int ste[131];
        memset(ste, 0, sizeof ste);
        bool ju[10];
        memset(ju, 0, sizeof ju);
        for (int i = 1; i <= n;i++)
        {
            ste[p[i][3]] = 1;
            for (int j = i+1; j <= n;j++)
            {
                if(p[i]==p[j])
                {
                    for (int k = 48; k <= 57;k++)
                    {
                        if(!ste[k])
                        {
                            if(!ju[j]&&ju[i])
                                p[i][3] = k, ju[i] = 1;
                            else if(ju[j]&&!ju[i])
                                p[j][3] = k, ju[j] = 1;
                            else
                                p[j][3] = k, ju[j] = 1;
                            ste[k] = 1;
                            break;
                        }
                    }
                }
            }
            cout << p[i] << endl;
        }
    }
}