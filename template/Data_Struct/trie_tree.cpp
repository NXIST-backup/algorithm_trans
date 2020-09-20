//高效地储存和查找字符串集合的数据结构


#include "iostream"
using namespace std;

const int N = 100010;

int son[N][26];//每个子节点有26的分支（字母）
int cnt[N], idx;//idx是下标，下标是0的点，既是根节点，又是空节点
char str[N];

void insert(char str[])//son[]<-父节点、son[][]<-字母、son[][]=key<-如果为空则创建当前下标，不为空则为当前下标
{
    int p = 0;
    for (int i = 0; str[i];i++)//c++里字符串结尾是0所以用来遍历
    {                          //输入abc,cdf,abd;
        int u = str[i] - 'a';//a~z映射成0~25 idx=3
        if (!son[p][u])      //son[0][0]=1 son[0][2]=4 son[0][0]=1
            son[p][u] = ++idx;//son[1][1]=2 son[4][3]=5 son[1][1]=2
        p = son[p][u];      //son[2][2]=3   son[5][4]=6 son[2][2]=3
    }                       //p=3;
    cnt[p]++;               //
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i];i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    cin >> str;
    insert(str);
    cout << idx << endl;
    cin >> str;
    insert(str);
    cout << cnt[3] << endl;
    cin >> str;
    insert(str);
    cout << cnt[3] << endl;
}