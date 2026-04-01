//Random Early Detection

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int buffer_size, packet_cnt;
	cout<<"Enter Buffer Size and Packet Count ";
	cin>>buffer_size>>packet_cnt;
	
	int limit = (buffer_size / 4) * 3; 
	
	vector<int> v(packet_cnt);
	for(int i = 0; i<packet_cnt; i++){
		cout<<"Enter Packet Id for " << i+1<<" packet : ";
		cin>>v[i];
	}
	for(int i = 0; i<packet_cnt; i++){
		if(i<limit) cout<<"Packet with id "<<v[i]<<" accepted"<<endl;
		else cout<<"Packet with id "<<v[i]<<" discarded"<<endl;
	}
	
}
