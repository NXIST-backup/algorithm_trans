//字符串前缀哈希法

//str="ABCDEFGHI"
//h[0]=0的哈希值
//h[1]="A"的哈希值
//h[2]="AB"的哈希值 以此类推

//那么如何定义字符串的哈希值呢，把每个字符当作x进制的数,那么每个前缀都可以看作是哈希值乘上
//p进制的数的和，由于数据可能过大所以我们需要对一个小数q求余
//notice:
//1.首字符不能定义成0 例如A!=0,如果A==0,那么AAAA..==0，哈希值会冲突。
//2.假定不可能冲突(p=131 or 13331,q=pow(2,64));

//advantage:
//通过前缀可以求得所有字串的hash value

#include "iostream"

using namespace std;

typedef unsigned long long ull;

const int N = 100010,P=131;

int n, m;
char str[N];
ull h[N], p[N];

ull get(int l,int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];//|________|______|_______|
}                                         //         L      R
                                          // L左移R-L+1位
int main()
{
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n;i++)
    {
        p[i] = p[i - 1] * P;//预处理p的进制
        h[i] = h[i - 1] * P + str[i];//求字符串哈希值前缀和
    }

    while(m--){

        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1,r1)==get(l2,r2))
            cout << "Yes" << endl;
            else
                cout << "No" << endl;
    }
}