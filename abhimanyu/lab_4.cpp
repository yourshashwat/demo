//signal encoding
#include<iostream>
#include<string>
using namespace std;

//eg; 1 0 0 0 0 1 0 1 1 1 1

int NRZ_L(string s)
{
	//whenever 0->1 or 1->0 then only count transition and return
	int transition_ct = 0;
	for(int i=1; i<s.length(); i++){
		if(s[i] != s[i-1]){
			transition_ct++;
		}
	}
	
	return transition_ct;
}

int NRZ_I(string s)
{
	//whenever '1' encounter then only count transition and return
	int transition_ct = 0;
	for(auto ch : s){
		if(ch == '1'){
			transition_ct++;
		}
	}
	
	return transition_ct;
}

int Bipolar_AMI(string s)
{
	//whenever 0<->0 encounters then dont't count transition and return
	int transition_ct = 0;
	for(int i=1; i<s.length(); i++){
		if(s[i]=='0' && s[i-1]=='0') continue;
		transition_ct++;
	}
	
	return transition_ct;
}

int Pseudoternary(string s)
{
	//whenever 0<->0 encounters then dont't count transition and return
	int transition_ct = 0;
	for(int i=1; i<s.length(); i++){
		if(s[i]=='1' && s[i-1]=='1') continue;
		transition_ct++;
	}
	
	return transition_ct;
}


int main()
{
	string str;
	cout<<"Enter string: ";
	cin>>str;
	
	cout<<"NRZ_L : "<<NRZ_L(str)<<endl;
	cout<<"NRZ_I : "<<NRZ_I(str)<<endl;
	cout<<"Bipolar : "<<Bipolar_AMI(str)<<endl;
	cout<<"Pseudoternary : "<<Pseudoternary(str)<<endl;
	
	return 0;
}
