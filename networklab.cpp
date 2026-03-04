#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b)
{
    string result = "";

    for(int i = 1; i < b.length(); i++)
    {
        if(a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

string crcDivision(string data, string generator)
{
    int g = generator.length();
    string temp = data.substr(0, g);

    for(int i = g; i < data.length(); i++)
    {
        if(temp[0] == '1')
            temp = xorOperation(generator, temp) + data[i];
        else
            temp = xorOperation(string(g,'0'), temp) + data[i];
    }

    if(temp[0] == '1')
        temp = xorOperation(generator, temp);
    else
        temp = xorOperation(string(g,'0'), temp);

    return temp;
}

int main()
{
    string data, generator;

    cout<<"Enter data: ";
    cin>>data;

    cout<<"Enter generator: ";
    cin>>generator;

    int r = generator.length()-1;

    string appendedData = data + string(r,'0');

    string remainder = crcDivision(appendedData, generator);

    string transmitted = data + remainder;

    cout<<"CRC: "<<remainder<<endl;
    cout<<"Transmitted data: "<<transmitted<<endl;
}



#include <iostream>
#include <vector>
using namespace std;

// Binary addition with carry
string binaryAdd(string a, string b)
{
    string result = "";
    int carry = 0;

    for(int i = a.length()-1; i >= 0; i--)
    {
        int sum = (a[i]-'0') + (b[i]-'0') + carry;

        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    // wrap-around carry
    if(carry == 1)
    {
        for(int i = result.length()-1; i >= 0; i--)
        {
            if(result[i] == '0')
            {
                result[i] = '1';
                carry = 0;
                break;
            }
            else
            {
                result[i] = '0';
            }
        }
    }

    return result;
}

// one's complement
string complement(string a)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == '0')
            a[i] = '1';
        else
            a[i] = '0';
    }
    return a;
}

int main()
{
    int n;
    cout<<"Enter number of segments: ";
    cin>>n;

    vector<string> data(n);

    cout<<"Enter binary data segments:\n";
    for(int i=0;i<n;i++)
        cin>>data[i];

    string sum = data[0];

    for(int i=1;i<n;i++)
        sum = binaryAdd(sum,data[i]);

    string checksum = complement(sum);

    cout<<"Checksum = "<<checksum<<endl;

    // Receiver side
    sum = binaryAdd(sum,checksum);

    if(sum.find('0') == string::npos)
        cout<<"No Error"<<endl;
    else
        cout<<"Error Detected"<<endl;
}



