//Leaky bucket algorithm
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n , m;
	cout<<"enter the value of buffer size & bucket size(leaky):\n";
	cin>>n>>m;
	vector<int>bucket(m);
	cout<<"enter the values of packets\n";
	for(int i=0; i<m; i++)
	cin>>bucket[i];
	
	int x = n;
	int i = 0;
	while(i<m)
	{
		if(i<m && n-bucket[i]>-1)
		{
			while(i<m && n-bucket[i]>-1)
			{
				cout<<"frame "<<bucket[i]<<" will flow "<<endl;
				n -= bucket[i];
				i++;
			}
		}
		else
		{
			cout<<"won't flow in this iteration"<<endl;
			n = x;
		}
		
	}
	return 0;
}
