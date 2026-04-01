#include <bits/stdc++.h>
using namespace std;

//Priority Based

int main()
{
	int buffer_size, pkt_count;
	cout << "Enter the buffer size: ";
	cin >> buffer_size;
	cout << "Enter the no. of packets: ";
	cin >> pkt_count;
	
	vector<pair<int,int>> priority(pkt_count);
	
	for(int i = 0; i < pkt_count; i++)
	{
		cout << "Enter the priority of packet " << (i + 1) << ": ";
		int p;
		cin >> p;
		priority[i] = {p, i+1};
	}
	
	sort(priority.rbegin(), priority.rend());
	
	for(int i=pkt_count-1 ; i>=buffer_size; i--){
		cout<<"Packet id "<< priority[i].second<<" | with priority "<<priority[i].first<<" is Discarded"<<endl;
	
	}
	
	return 0;
}
