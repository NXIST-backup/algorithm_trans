#include "iostream"
#include "vector"
#include<map>
using namespace std;
bool b[2];
int q[200005];
int n, k;
map<int, bool> P;
int main()
{
    
    cin >> n >> k;
    int hh = 0;
    int tt = -1;
    
    for (int i = 0; i < n;i++)
    {        
        int x;
        cin >> x;
        q[++tt] = x;
        if(P[x]>0)
            tt--;
        P[x] = true;
        if (tt-hh>=k)
        {
            P[q[hh]] = 0;
            hh++;
        }
    }
    cout << tt+1  - hh << endl;
    for (int i = tt; i >= hh;i--)
        cout << q[i] << " ";
}