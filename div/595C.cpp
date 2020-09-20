#include "iostream"
#include "cmath"
using namespace std;

int q;
int n;
bool judge[10000];
int main()
{
    cin >> q;
    while(q--){

        cin >> n;
        int flag = 1;
        for (int i = n;flag;i++)
        {
           
            int t = i;
            for (int j = 9; j >= 0; j--)
            {
                if (t >= pow(3, j))
                {
                    t -= pow(3, j);
                }
                if(t==0)
                {
                    flag = 0;
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}