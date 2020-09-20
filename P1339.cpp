#include<iostream>
#include<algorithm>
using namespace std;
int arr[]={1,2,3,4,5,6,7,8,9}; 
int getNum(int i,int j)
{
  int sum=0;
  for(int t=i;t<=j;t++)
   sum=sum*10+arr[t];
  return sum;
}
int main()
{
   int num=0;
   int N;
   cin>>N;
  do{
    
	for(int i=0;i<=6;i++)
		    {
		      for(int j=i+1;j<8;j++)
		      {
		        int num1=getNum(0,i);
            int num2=getNum(i+1,j);
            int num3=getNum(j+1,8);
            cout << num1 << "+" << num2 << "/" << num3 << endl;
            if(num2%num3==0&&(num1+num2/num3==N))
		         num++;
		      }
		    }
    
  }while(next_permutation(arr,arr+9));
  cout<<num;
  return 0;
}