#include <bits/stdc++.h>
#include <thread>
using namespace std;

//Random selection of packets

int main()
{
	srand(time(0));
	int buffer_size, packets, threshold;
	cout << "Enter the buffer size: ";
	cin >> buffer_size;
	cout << "Enter the no. of packets: ";
	cin >> packets;
	cout << "Enter the threshold: ";
	cin >> threshold;
	int n = packets;
	set<int> dropped;
	
	while (packets > threshold)
	{
		int random = rand() % n;
		if (dropped.find(random) == dropped.end()){
			packets -= 1;
			cout << endl << "Packet " << random << " dropped" << endl;
			dropped.insert(random);
		}
	}
	
	return 0;
}
