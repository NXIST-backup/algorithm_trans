#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    string str1;
    cin >> str;                      //将输入的数字存进字符串中
    str1 = str;                      //将反转之前的值给str1
    reverse(str.begin(), str.end()); //反转字符串
    if (str.compare(str1) == 0) {    //比较反转之前和反转之后的大小
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}