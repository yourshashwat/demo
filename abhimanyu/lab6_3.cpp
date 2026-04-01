//shanon capacity
#include<bits/stdc++.h>
using namespace std;

double calculateShannonCapacity(double bandwidth, int signalByNoisePower) {
    // Shannon Capacity Formula: C = B * log2(1 + S/N)
    return bandwidth *log2(1 + signalByNoisePower);
}

int main() {
    double bandwidth;
    int signalByNoisePower;

   cout << "Enter bandwidth (Hz): ";
   cin >> bandwidth;

   cout << "Enter signal to Noise power (S/N): ";
   cin >> signalByNoisePower;

    double capacity = calculateShannonCapacity(bandwidth, signalByNoisePower);
    cout << "The Shannon Channel Capacity is: " << capacity << " bps" <<endl;

    return 0;
}
