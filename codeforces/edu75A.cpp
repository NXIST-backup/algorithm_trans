#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;

int t;

string a;

int main()
{

    cin >> t;
    while(t--){
        int h[26] = {0};
        cin >> a;
        int cnt = 1;
        char t=a[0];
        a.push_back('A');
        if(a.size()==1)
            h[0] = 1;
        else
        for (int i = 1; i <= a.size();i++)
        {
            
            if(a[i]!=t)
            {
                if(cnt%2)
                h[a[i - 1] - 'a'] = cnt % 2;
                cnt = 1;
            }
            
            else
                cnt++;
            t = a[i];
        }

        for (int i = 0;i<26;i++)
        if(h[i])
            printf("%c", 'a' + i);
        cout << endl;
    }
}