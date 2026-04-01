//Manchester, differential manchester, simple parity, two dimensional parity
#include<bits/stdc++.h>
using namespace std;

//01001100011

//Manchester
//0->0 change
//1->1 change
//change on each bit input
int manchester(string s)
{
	int tot_count = 0;
	for(int i=0;i<s.length();i++)
	{
		if(i+1<s.length() && s[i] == s[i+1]){
			tot_count++;
		}
		tot_count++;
	}
	
	return tot_count;
}

//differential manchester
//0->0 no change
//1->0 no change
//change on each bit input
int diff_Manchester(string s)
{
	int tot_count = 0;
	if(s[0] == '0') tot_count++ ;
	for(int i=0;i<s.length();i++)
	{
		if(i+1<s.length() && s[i]=='1' && s[i+1]=='0'){
			tot_count++;
		}
		if(i+1<s.length() && s[i]=='0' && s[i+1]=='0'){
			tot_count++;
		}
		tot_count++;
	}
	
	return tot_count;
}

//simple parity
//take string as input then ask user to change any bit if user want to show the error
string simple_Parity_check(string ori_str, string command, int bit_idx)
{
	string copy_str = ori_str;
	if(command == "yes"){
		if(copy_str[bit_idx] == '0') copy_str[bit_idx] = '1';
		if(copy_str[bit_idx] == '1') copy_str[bit_idx] = '0';
	}
	bool isValidData = true;
	int even_ct = 0;
	for(int i=0;i<ori_str.length();i++){
		if(ori_str[i] != copy_str[i]) isValidData = false;
		if(copy_str[i] == '1') even_ct++;
	}
	
	if(isValidData && even_ct%2==0){
		return "Yes Data is Safe";
	}
	
	return "Error in Data";
}

//2D parity

string parity_2D(string s){
	while(s.length() % 8 != 0){
		s += '0';
	}
	int n = s.length();
	int one_cnt = 0;
	vector<bool> row_parity(n/8,0);
	vector<bool> col_parity(9,0);
	
	for(int i = 0; i<n; i++){
		if(s[i] == '1'){
			row_parity[i/8] = !row_parity[i/8];
			col_parity[i%8] = !col_parity[i%8];
		}
	}
	for(int i = 0; i<col_parity.size(); i++){
		if(col_parity[i]) col_parity[8] = !col_parity[8];
	}
	cout<<"Output String : ";
  
	for(int i = 0; i<n; i++){
		cout<<s[i];
    
		if((i+1)%8 == 0) cout<<row_parity[i/8];
	}
	
	for(int i = 0; i<9; i++){
		cout<<col_parity[i];
	}
	
	cout<<endl;
	return "";
}

int main()
{
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	
	cout<<"Manchester Total Count: "<<manchester(str)<<endl;
	cout<<"Differential Manchester Total Count: "<<diff_Manchester(str)<<endl;
	
	//simple parity check
	cout<<endl;
	string s;
	cout<<"Enter string for simple parity check: ";
	cin>>s;
	string command;
	int bit_idx = 0;
	cout<<"Do you want to change the data bit for simple parity (yes/no): ";
	cin>>command;
	if(command == "yes"){
		cout<<"Enter the bit index you want to change: ";
		cin>>bit_idx;
	}
	cout<<"Result: "<<simple_Parity_check(s, command, bit_idx)<<endl;
	
	//2D parity check
	cout<<endl;
	string s_2D;
	cout<<"Enter string for 2D parity check: ";
	cin>>s_2D;
	cout<<"Result: "<<parity_2D(s_2D)<<endl;
	
	return 0;
}

