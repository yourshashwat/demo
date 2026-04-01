#include <bits/stdc++.h>
using namespace std;

// Function to calculate number of redundant bits needed
int calculateRedundantBit(int m) {
    int r = 0;
    while ((1 << r) < m + r + 1) r++;
    return r;
}

int main() {
    string signal;
    cout << "Enter data bits: ";
    cin >> signal;

    int m = signal.length();
    int r = calculateRedundantBit(m);
    int n = m + r;
    vector<int> v(n + 1); // 1-based indexing
    int j = m - 1;

    // Insert data bits and leave parity bit positions as 0
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) // power of 2 => parity bit
            v[i] = 0;
        else
            v[i] = signal[j--] - '0';
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int pos = 1 << i;
        int sum = 0;
        for (int k = 1; k <= n; k++) {
            if (k & pos)
                sum += v[k];
        }
        v[pos] = sum % 2;
    }

    cout << "\nGenerated Hamming code: \n";
    for (int i = n; i >= 1; i--)
        cout << v[i] << " ";
    cout << endl;

    // Error detection
    cout << "\nEnter received code: ";
    vector<int> recv(n + 1);
    for (int i = n; i >= 1; i--)
        cin >> recv[i];

    int errorPos = 0;
    for (int i = 0; i < r; i++) {
        int pos = 1 << i;
        int sum = 0;
        for (int k = 1; k <= n; k++) {
            if (k & pos)
                sum += recv[k];
        }
        if (sum % 2 != 0)
            errorPos += pos;
    }

    if (errorPos == 0)
        cout << "\nNo error detected\n";
    else {
        cout << "\nError detected at position: " << errorPos << endl;
        recv[errorPos] ^= 1; // correct the bit
        cout << "Corrected code: \n";
        for (int i = n; i >= 1; i--)
            cout << recv[i] << " ";
        cout << endl;
    }

    return 0;
}
