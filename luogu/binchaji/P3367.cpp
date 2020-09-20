#include "iostream"
using namespace std;

int n, m;

int p[200050];

int find(int x)
{
    if(p[x]!=x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        p[i] = i;

    cin >> m;

    while(m--){

        int z, x, y;

        cin >> z >> x >> y;

        if(z==1)
        {
            int px = find(x), py = find(y);

            p[px] = py;

        }
        else
        {
            if(find(x)==find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
}