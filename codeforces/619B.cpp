#include "iostream"
#include "algorithm"
#include <stdlib.h>
#include "vector"
using namespace std;

int t;
int n;
const int N = 2e5 + 50;
int array[N];
int sub[N];
vector<int> sa;
int main()
{
    cin >> t;

    while (t--) {

        cin >> n;
        sa.clear();
        for (int i = 1; i <= n;i++)
        {
            cin >> array[i];
            sub[i] = array[i];
        }
        int maxN = 0;
        int st = 0, ed = 0;
    
        for (int i = 1; i <= n;i++)
        {
            if(array[i]==-1)
            {
                if(i!=1&&array[i-1]!=-1)
                    sa.push_back(array[i - 1]);
                if(array[i+1]!=-1&&i!=n)
                    sa.push_back(array[i + 1]);
            }
        }

        sort(sa.begin(), sa.end());
        if(sa.size())
            st = sa[0];
        else
            st = 0;
        if(!sa.size())
            ed = 0;
        else
            ed = sa.back();

        int mid = (st + ed) / 2;
        for (int i = 1; i <= n;i++)
        {
            if(sub[i]==-1)
                sub[i] = mid;
        }
        for (int i = 1; i < n;i++)
        {
            maxN = max(maxN, abs(sub[i] - sub[i + 1]));
        }

        cout << maxN << " " << mid << endl;
    }
}
