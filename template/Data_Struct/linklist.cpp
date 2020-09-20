//单链表可以写邻接表
//邻接表可以存图和树
//双链表:优化某些问题
#include "iostream"

using namespace std;

int head;
int idx;//尾指针
int e[100010];
int ne[100010];

void init()
{
    idx = 0;
    head = -1;
}

void insert_h(int i)
{
    e[idx] = i; 
    ne[idx] = head;
    head = idx; 
    idx++;
}
void insert(int x,int k)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
void del(int k)
{
    ne[k] = ne[ne[k]];
}
int find(int x)
{
    for (int i = head; i != -1;i=ne[i])
    {
        if(e[i]==x)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return -1;
}
int main()
{
    init();
    cout << "how many numbers you want to insert" << endl;
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        insert_h(x);
    }

    int ans;
    cin >> ans;

    find(ans);
}