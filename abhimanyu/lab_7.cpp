//networking lab
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

bool isLost() {
    return rand() % 5 < 1;
}

void stopAndWaitARQ(int frames) {
    cout << "\n--- Stop-and-Wait ARQ ---\n";
    for (int i = 0; i < frames; i++) {
        cout << "Sending frame " << i << "...\n";
        if (isLost()) {
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Frame lost! Resending...\n";
            i--;
        } else {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Acknowledgement received.\n";
        }
    }
}

void gobackNARQ(int frames, int windowSize) {
    cout << "\n--- Go-Back-N ARQ ---\n";
    int base = 0;

    while (base < frames) {
        int i;
        cout << "Sending frame: ";
        for (i = base; i < min(base + windowSize, frames); i++) {
            cout << i << " ";
        }
        cout << endl;

        for (i = base; i < min(base + windowSize, frames); i++) {
            if (isLost()) {
                cout << "Frame " << i << " lost! Resending from frame " << i << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
            } else {
                cout << "Ack received for frame " << i << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
        base = i;
    }
}

void selectiveRepeatARQ(int frames, int windowSize) {
    cout << "\n--- Selective-Repeat ARQ (Selective-Reject) ---\n";
    vector<bool> ack(frames, false);
    int base = 0;

    while (base < frames) {
        for (int i = base; i < min(base + windowSize, frames); i++) {
            if (!ack[i]) {
                cout << "Sending frame " << i << "...\n";
                if (isLost()) {
                    cout << "Frame lost! Resending later.\n";
                    this_thread::sleep_for(chrono::seconds(2));
                } else {
                    cout << "Ack received.\n";
                    ack[i] = true;
                    this_thread::sleep_for(chrono::milliseconds(500));
                }
            }
        }

        while (base < frames && ack[base])
            base++;
    }
}

int main() {
    srand(time(0));

    int totalFrames, windowSize;

    cout << "Enter number of total frames: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    stopAndWaitARQ(totalFrames);
    gobackNARQ(totalFrames, windowSize);
    selectiveRepeatARQ(totalFrames, windowSize);

    return 0;
}

