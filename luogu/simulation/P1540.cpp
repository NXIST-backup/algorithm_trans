#include "iostream"
#include <vector>
#include "queue"

using namespace std;

int m, n;
vector<int> me;

int main()
{

    cin >> m >> n;
    int cnt = n;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        int flag = 0;
        for(auto item:me)
        {
            if(x==item)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cnt--;
        else
        {
            me.push_back(x);
            if(me.size()>m)
                me.erase(me.begin());//erase用法
        }
    }

    cout << cnt << endl;
}
