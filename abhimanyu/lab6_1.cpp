//CRC
#include<bits/stdc++.h>
using namespace std;

string Xor(string a, string b) {
    string res = "";
    for(int i = 1; i < b.length(); i++) {
        if(a[i] == b[i])
            res += '0';
        else
            res += '1';
    }
    return res;
}

string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);

    while(pick < dividend.length()) {
        if(tmp[0] == '1')
            tmp = Xor(divisor, tmp) + dividend[pick];
        else
            tmp = Xor(string(pick, '0'), tmp) + dividend[pick];

        pick++;
    }

    if(tmp[0] == '1')
        tmp = Xor(divisor, tmp);
    else
        tmp = Xor(string(pick, '0'), tmp);

    return tmp;
} 

int main() {
    string data, generator;
    cout << "Enter Data: ";
    cin >> data;
    cout << "Enter Generator: ";
    cin >> generator;

    int m = generator.length();


    string appended = data + string(m-1, '0');
    string rem = mod2div(appended, generator);
    string transmitted = data + rem;

    cout << "\nSender Side:";
    cout << "\nCRC Remainder: " << rem;
    cout << "\nTransmitted Data: " << transmitted << endl;


    return 0;
}

