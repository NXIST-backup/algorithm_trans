#include "iostream"
#include <stdio.h>

using namespace std;

string a;
char c;
int main()
{
    int flag = 0;
    while ((c=getchar())!='E') {

        if(c=='W'||c=='L')
            a.push_back(c);
    }
    int lose = 0, win = 0;
    if(!a.size())
    {
        cout << 0 << ':' << 0 << endl;
        cout << endl;
        cout << 0 << ':' << 0 << endl;
    }
    else
    {
        for (int i = 0; i < a.size();i++)
        {
            if(a[i]=='W')
                win++;
            if(a[i]=='L')
                lose++;
            if(win>=11||lose>=11)
            {
                if(win-lose>=2||i==a.size()-1||lose-win>=2)
                {
                    if(win-lose>=2||lose-win>= 2)
                        flag = 1;
                    cout << win << ':' << lose << endl;
                    win = 0;
                    lose = 0;
                }
                else
                    continue;
            }
            if(i==a.size()-1&&flag)
            {
                cout << win << ':' << lose << endl;
                win = 0;
                lose = 0;
            }
        }
    
        cout << endl;
        for (int i = 0; i < a.size();i++)
        {
            if(a[i]=='W')
                win++;
            if(a[i]=='L')
                lose++;
            if (win >= 21||lose >= 21)
            {
                if(win-lose>=2||i==a.size()-1||lose-win>=2)
                {
                    if(win-lose>=2||lose-win)
                        flag = 1;
                    cout << win << ':' << lose << endl;
                    win = 0;
                    lose = 0;
                }
                else
                    continue;
            }
            if(i==a.size()-1&&flag)
                cout << win << ':' << lose << endl;
        }
    }
}  