#include "iostream"
using namespace std;
int n, m;
int p[100050], size1[100050];

int find(int x)
{
	if(p[x]!=x)
		p[x] = find(p[x]);
	return p[x];
}


int main()
{
	cin >> n >> m;
	string a;
	for (int i = 1; i <= n;i++)
	{
		p[i] = i;
		size1[i] = 1;
	}
	while(m--){
		int b, c;
		cin >> a;
		if(a=="C")
		{
			cin >> b >> c;

			b = find(b), c = find(c);

			if(b!=c){
				size1[c] += size1[b];
				p[b] = c;
			}
		}
		else if (a=="Q1") {
			cin >> b >> c;
			if(find(b)==find(c))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			cin >> b;
			cout << size1[find(b)] << endl;
		}


	}
}