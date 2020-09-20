#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

bool pan(double x1, double y1, double x2, double y2,double x3, double y3, double x4, double y4,double& X, double& Y)
{
	double a=x2-x1,b=x3-x4,c=y2-y1,d=y3-y4,g=x3-x1,h=y3-y1,f=a*d-b*c,t,s;
	if(fabs(f)<1.0e-06)
	{
		return false;
	}
	t=(d*g-b*h)/f;
	s=(-c*g+a*h)/f;
	if((0>t) || (t>1))
	{
		return false;
	}
	if((0>s) || (s>1))
	{
		return false;
	}
	X=x1+t*(x2-x1);
	Y=y1+t*(y2-y1);
	return true;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
	 	double x1,x2,x3,x4,y1,y2,y3,y4,X,Y;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		bool ka;
		ka=pan(x1,y1,x2,y2,x3,y3,x4,y4,X,Y);
		cout << ka << endl;
		printf("%f %f\n", X, Y);
		if(ka && (x2 != x4 || y2 != y4) && (x2 != X || y2 != Y) && (x4 != X || y4 != Y))
		{
			if(0.5*(x2*y4+x4*Y+X*y2-x2*Y-x4*y2-X*y4) > 0)
			{
		 	 	printf("%.2lf\n",0.5*(x2*y4+x4*Y+X*y2-x2*Y-x4*y2-X*y4));
		 	}
			else
			{
				printf("%.2lf\n",-0.5*(x2*y4+x4*Y+X*y2-x2*Y-x4*y2-X*y4));
			}
		}
		else
		{
			printf("*0\n");
		}
	}
}