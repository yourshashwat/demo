//checksum
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
	int carry = 0;
	string ans = "########";
	for(int i = 7; i>=0; i--){
		int x = a[i] - '0';
		int y = b[i] - '0';
		int curr = x + y + carry;
		ans[i] = curr%2 + '0';
		carry = curr/2;
	}
	for(int i = 7; i>=0; i--){
		int curr = ans[i] - '0' + carry;
		ans[i] = curr%2 + '0';
		carry = (curr)/2;
	}
	return ans;
}

string checkSum(string str){
	while(str.length() % 8 != 0) str += '0';
	string prev = "00000000";
	for(int i = 0; i<str.length(); i+=8){
		prev = add(prev, str.substr(i,8));
	}
	string ans = "";
	for(int i = 0; i<8; i++) ans += prev[i] == '1' ? '0' : '1';
	return ans;

}

int main(){
	string str;
	cout<<"Enter String ";
	cin>>str;
	cout<<"Ones Complement of Sum : "<<checkSum(str)<<endl;
 	return 0;
}
