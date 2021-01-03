#include "iostream"

using namespace std;

const int N = 8e5 + 50;

int p[N];
int n;
int t;


int main()
{
    cin >> t;
    while (t--) {

        cin >> n;

        for (int i = 1; i <= n;i++)
        {
            cin >> p[i];
        }

        int temp = n / 2;

        while(p[temp]==p[temp+1])
        {
            temp--;
        }
        if(n<10)
            cout << "0 0 0" << endl;
        else
        {
            int t = 1;
            int g_temp = 0;
            while(p[t++]==p[1])
            {
                g_temp++;
            }
            int s_temp = g_temp*2+1;
            while(p[s_temp]==p[s_temp+1])
            {
                s_temp++;
            }
            if(temp-s_temp>g_temp)
            {
                cout << g_temp << " " << s_temp - g_temp << " " << temp - s_temp << endl;
            }
            else
                cout << "0 0 0" << endl;
        }
    }
}