#include "iostream"

using namespace std;
int main()
{
    int t;
    cin >> t;
    int exp;
    int str, iti;
    while(t--)
    {
        cin >> str >> iti >> exp;
        int sol = str + iti + exp;
        int ans = sol - (sol / 2) - iti;

        if(str>iti)
        {
            if(exp<str-iti)
            {
                ans = exp + 1;
            }
            else
            {
                ans = exp - (exp - (str - iti)) / 2;
            }
            printf("%d\n", ans);
        }
        else
        {
            if(ans>=0)
            printf("%d\n",ans);
            else
            printf("%d\n", 0);
        }
    }

}