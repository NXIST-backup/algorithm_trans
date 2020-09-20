//-----------------------  ——开放寻址法
//---------——存储结构----- ——拉链法
//  哈希表-----------------------------
//---------——字符串哈希方式
//-----------------------

//哈希数组取质数 尽可能离2的幂远一点
//csdn:
// 哈希表的大小取决于一组质数，原因是在hash函数中，你要用这些质数来做模运算(%)。
// 而分析发现，如果不是用质数来做模运算的话，很多生活中的数据分布，会集中在某些点上。
// 所以这里最后采用了质数做模的除数。

// 因为用质数做了模的除数，自然存储空间的大小也用质数了，因为模完之后，数据是在[0-所选质数)之间。

//拉链法
#include "iostream"
#include "cstring"
using namespace std;
const int N = 100003;

int h[N],e[N],ne[N],idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1;i=ne[i])
    if(e[i]==x)
        return true;
}


int main()
{
    int n;
    cin >> n;

    memset(h, -1, sizeof h); //head=-1;

    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if(*op == 'I')
            insert(x);
        else
        {
            if(find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
}
