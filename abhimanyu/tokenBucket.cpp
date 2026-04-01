//Token Bucket Algo
#include<bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
bool send() {
    return rand() % 5 < 1;
}
int main()
{
	int bucket;
	cout<<"enter the capacity of bucket(token)\n";
	cin>>bucket;
	cout<<"enter the rate of tokens\n";
	int rot;
	cin>>rot;
	int i=0;
	while(bucket > 0)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		bucket -= rot;
		if(bucket <= 0)
		{
			cout<<"the bucket is filled"<<endl;
			return 0;
		}
		if(send())
		{
			cout<<"enter the request packet "<<endl;
			int rp;
			cin>>rp;
			bucket += rp;
		}
		cout<<"remainint size : "<<bucket<<endl;
		i++;
	}
	return 0;
}
