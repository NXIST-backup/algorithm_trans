#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int x, y;
string z;
vector<int> number;

int main()
{
	cin >> x >> y >> z;
	
	for(int i = 0; i < z.length(); i++)
	{
		if(z[i] >= '0' && z[i] <= '9')
        {
            number.push_back(z[i] - '0');
        }
        if(z[i] >= 'A' && z[i] <= 'Z') 
        {
            number.push_back(z[i] - 'A' + 10);
        }
        if(z[i] >= 'a' && z[i] <= 'z')
        {
            number.push_back(z[i] - 'a' + 36);
        }
	}
	
	reverse(number.begin(), number.end());
	
	vector<int> ans;
	
	while(number.size())
	{
		int r = 0;
		for(int i = number.size()-1; i >= 0; i--)
		{            
            number[i] += r*x;
			r = number[i]%y;
			number[i]/=y;
		}
		ans.push_back(r);
		
		while(number.size() && number.back() == 0)
			number.pop_back();
	}
	
	reverse(ans.begin(), ans.end());
	
	string res = "";
	
	for(int i = 0; i < ans.size(); i++)
	{
		x = ans[i];
		if(x <= 9)
            res += char(x + '0');
        if(x >= 10 && x <= 35)
            res += char(x + 'A' - 10);
        if(x >= 36)
            res += char(x + 'a' - 36);
	}
	cout << res << endl;
}