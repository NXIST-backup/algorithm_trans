//大模拟，纯恶心


#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int p1, p2, p3;
string s1;

int main()
{
    cin >> p1 >> p2 >> p3;

    cin >> s1;

    for (int i = 0; i < s1.size();i++)
    {
        if(s1[i]!='-'||i==0||(i-1==0&&s1[i-1]=='-'))
            cout << s1[i];
        else
        {
            char a1 = s1[i - 1];
            char a2 = s1[i + 1];
            if(a2-a1<=25&&a2>a1)
            {
                if(p3==1)
                {
                    if(a1<=57)
                    {
                        if(p1==3)
                        {
                            for (int i = a1 + 1; i <= a2 - 1;i++)
                            {
                                for (int j = 1; j <= p2;j++)
                                    printf("%c", '*');
                            }                            
                        }
                        else
                        {
                            for (int i = a1 + 1; i <= a2 - 1;i++)
                            {
                                for (int j = 1; j <= p2;j++)
                                    printf("%c", i);
                            }
                        }
                    }
                    else
                    {
                        if(a1>=97)
                        {
                            if(p1==1)
                            {
                                for (int i = a1 + 1; i <= a2 - 1;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else if(p1==2)
                            {
                                for (int i = a1 + 1 - 32; i <= a2 - 1-32;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else
                            {
                                for (int i = a1 + 1; i <= a2 - 1;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", '*');
                                }
                            }
                        }
                        else
                        {
                            if(p1==1)
                            {
                                for (int i = a1 + 1; i <= a2 - 1;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else if(p1==2)
                            {
                                for (int i = a1 + 1 + 32; i <= a2 - 1+32;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else
                            {
                                for (int i = a1 + 1; i <= a2 - 1;i++)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", '*');
                                }
                            }                            
                        }
                    }
                }
                else
                {
                    if(a1<=57)
                    {
                        if(p1==3)
                        {
                            for (int i = a2 - 1; i >= a1 + 1;i--)
                            {
                                for (int j = 1; j <= p2;j++)
                                    printf("%c", '*');
                            }                            
                        }
                        else
                        {
                            for (int i = a2 - 1; i >= a1 + 1;i--)
                            {
                                for (int j = 1; j <= p2;j++)
                                    printf("%c", i);
                            }
                        }
                    }
                    else
                    {
                        if(a1>=97)
                        {
                            if(p1==1)
                            {
                                for (int i = a2 - 1; i >= a1 + 1;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else if(p1==2)
                            {
                                for (int i = a2 - 1 - 32; i >= a1 + 1-32;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else
                            {
                                for (int i = a2 - 1; i >= a1 - 1;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", '*');
                                }
                            }
                        }
                        else
                        {
                            if(p1==1)
                            {
                                for (int i = a2 - 1; i >= a1 + 1;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else if(p1==2)
                            {
                                for (int i = a2 - 1 + 32; i >= a1 + 1+32;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", i);
                                }
                            }
                            else
                            {
                                for (int i = a2 - 1; i >= a1 + 1;i--)
                                {
                                    for (int j = 1; j <= p2;j++)
                                        printf("%c", '*');
                                }
                            }                            
                        }
                    }
                }
            }
            else
                cout << s1[i];
        }
    }
}