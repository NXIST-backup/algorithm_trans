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
        int str2;
        int iti2;
        int cnt = 0;
        if(str>iti)
        {
            if(exp<str-iti)
            {
                cnt = exp + 1;
            }
            else
            {
                cnt = exp - (exp - (str - iti)) / 2;
            }
        }
        else
        {
        for (int i = 0; i <= exp;i++)
        {
            str2 = str;
            iti2 = iti;
            str2 += exp-i;
            iti2 += i;
            if(str2>iti2)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        }
        printf("%d\n", cnt);
    }
}