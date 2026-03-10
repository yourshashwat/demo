#include <bits/stdc++.h>
using namespace std;

int calculateRedundantBits(int m){
    int r = 0;
    while((1<<r) < m + r + 1) r++;
    return r;
}

int main(){

    string signal;
    cout<<"Enter data bits: ";
    cin>>signal;

    int m = signal.length();
    int r = calculateRedundantBits(m);

    int n = m + r;

    vector<int> v(n+1);

    int j = m-1;

    // Insert data and leave parity positions
    for(int i=1;i<=n;i++){
        if((i & (i-1)) == 0)
            v[i] = 0;
        else
            v[i] = signal[j--] - '0';
    }

    // Calculate parity bits
    for(int i=0;i<r;i++){
        int pos = 1<<i;
        int sum = 0;

        for(int k=1;k<=n;k++){
            if(k & pos)
                sum += v[k];
        }

        v[pos] = sum % 2;
    }

    cout<<"\nGenerated Hamming Code:\n";
    for(int i=n;i>=1;i--)
        cout<<v[i]<<" ";
    cout<<endl;

    // -------- Error Detection --------

    cout<<"\nEnter received code: ";
    vector<int> recv(n+1);

    for(int i=n;i>=1;i--)
        cin>>recv[i];

    int errorPos = 0;

    for(int i=0;i<r;i++){
        int pos = 1<<i;
        int sum = 0;

        for(int k=1;k<=n;k++){
            if(k & pos)
                sum += recv[k];
        }

        if(sum % 2 != 0)
            errorPos += pos;
    }

    if(errorPos == 0)
        cout<<"\nNo error detected\n";
    else{
        cout<<"\nError at position: "<<errorPos<<endl;

        recv[errorPos] ^= 1;

        cout<<"Corrected code:\n";
        for(int i=n;i>=1;i--)
            cout<<recv[i]<<" ";
    }

}
