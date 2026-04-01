#include <bits/stdc++.h>
using namespace std;

//Application based

int main()
{
	int buffer_size, packets, threshold;
	char app;
	cout << "Enter the buffer size: ";
	cin >> buffer_size;
	cout << "Enter the no. of packets: ";
	cin >> packets;
	cout << "Enter the threshold: ";
	cin >> threshold;
	cout << "Enter the application type(M or F): ";
	cin >> app;
	int n = packets;
	int i = 0;
	
	while (packets > threshold)
	{
		if(app == 'M')
		
			cout << endl << "Packet " << (i + 1) << " discarded" << endl;
		
		else
			cout << endl << "Packet " << (n - i - 1) << " discarded" << endl;
		i += 1;
		packets -= 1;
	}
	
	return 0;
}
