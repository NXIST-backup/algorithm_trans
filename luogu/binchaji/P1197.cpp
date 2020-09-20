//逆序做 既然毁灭很难那就建造


#include "iostream"
using namespace std;

const int M = 200050,N=2*M;

int p[N];
int size1[N];

int n, m, k;


int find(int x)
{
    if(p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}


int main()
{
    cin >> n >> m;
    int t = n;
    for (int i = 1; i <= n;i++)
    {
        p[i] = i;
        size1[i] = 1;
    }

    for (int i = 1; i <= m;i++)
    {
        int x, y;
        cin >> x >> y;

        x = find(x), y = find(y);

        if(x!=y)
        {
            size1[x]++;
            t--;
            p[x] = find(y);
        }
        else
        {

        }
    }
    cout << t << endl;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        cout << t + size1[x] << endl;
    }
}