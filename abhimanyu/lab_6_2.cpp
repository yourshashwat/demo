//bit stuffing , after 5 ones we have to put a 0
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string input;
	cout<<"Enter input string for byte stuffing: ";
	cin>>input;
	cout<<"\n Bits before stuffing: "<<input<<endl;
	
	vector<int> store;
	int count = 0;
	int i=0;
	while(i < input.length())
	{
		if(input[i] == '1')
		{
			count = 0;
			while(input[i] == '1'){
				count++;
				store.push_back(1);
				
				if(count == 5){
					store.push_back(0);
					count=0;
				}
				i++;
			}
		}	
		if(input[i] == '0')
			store.push_back(0);
		i++;
	}
	
	//printing
	cout<<"Bits after Stuffing: ";
	for(auto a : store){
		cout<<a<<"|";
	}
	cout<<endl;
	return 0;
}
