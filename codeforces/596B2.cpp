#pragma GCC optimize(2)
#include "iostream"
#include "cstring"
using namespace std;
//队列
int t;
int n, k, d;

const int N = 1e6+50;



int main()
{
    cin >> t;

    while(t--){

        cin >> n >> k >> d;

        int que[N], tt = 0, ss = 1;
        for (int i = 1; i <= n;i++)
            cin >> que[i];
        int judge[N];
        memset(judge, 0, sizeof judge);
        int cnt = 0;
        int minN = 1e9 + 1;
        while(tt<n){

            tt++;
            if(judge[que[tt]]==0)
                cnt++;
            judge[que[tt]]++;
            if(tt-ss>=d)
            {
                judge[que[ss]]--;
                if(judge[que[ss]]==0)
                    cnt--;
                ss++;
            }

            if(tt-ss==d-1&&cnt<minN)
                minN = cnt;
        }
        cout << minN << endl;
    }

}
