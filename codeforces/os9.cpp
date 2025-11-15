#include <bits/stdc++.h>
using namespace std;

void FIFO(vector<int>& pages, int fcnt) {
    vector<int> frames(fcnt, -1);
    int pageFaults = 0, nextToReplace = 0;

    cout << "\n-> FIFO Page Replacement\n";

    for (auto page : pages) {
        bool found = count(frames.begin(), frames.end(), page);
        if (!found) {
            frames[nextToReplace] = page;
            nextToReplace = (nextToReplace + 1) % fcnt;
            pageFaults++;
        }
        for (auto f : frames) cout << (f == -1 ? string("-") : to_string(f)) << " ";
        cout << endl;
    }
    
    cout << "\nNo. of Page Faults = " << pageFaults << "\n"; 
}

void LRU(vector<int>& pages, int fcnt) {
    vector<int> frames;
    map<int, int> lastUsed; 
    int pageFaults = 0;

    cout << "\n-> LRU Page Replacement\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool found = count(frames.begin(), frames.end(), page);

        if (!found) {
            if (frames.size() < fcnt)
                frames.push_back(page);
            else {
                int lruPage = frames[0];
                for (auto f : frames)
                    if (lastUsed[f] < lastUsed[lruPage])
                        lruPage = f;

                replace(frames.begin(), frames.end(), lruPage, page);
            }
            pageFaults++;
        }

        lastUsed[page] = i;

        for (auto f : frames) cout << (f == -1 ? string("-") : to_string(f)) << " ";
        cout << endl;
    }

    cout << "\nNo. of Page Faults = " << pageFaults << "\n";
}

void Optimal(vector<int>& pages, int fcnt) {
    vector<int> frames;
    int pageFaults = 0;

    cout << "\n-> Optimal Page Replacement\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool found = count(frames.begin(), frames.end(), page);

        if (!found) {
            if (frames.size() < fcnt)
                frames.push_back(page);
            else {
                int indexToReplace = -1, farthest = i + 1;

                for (int f : frames) {
                    int j;
                    for (j = i + 1; j < pages.size(); j++)
                        if (pages[j] == f) break;

                    if (j > farthest) {
                        farthest = j;
                        indexToReplace = f;
                    }
                }

                if (indexToReplace == -1)
                    indexToReplace = frames[0];

                replace(frames.begin(), frames.end(), indexToReplace, page);
            }
            pageFaults++;
        }

        for (auto f : frames) cout << (f == -1 ? string("-") : to_string(f)) << " ";
        cout << endl;
    }

    cout << "\nNo. of Page Faults = " << pageFaults << "\n";
}

int main() {
    int choice;
    vector<int> pages;
    int n, frameCount;

    do {
        cout << "\nPage Replacement Algorithms:\n";
        cout << "1. FIFO\n";
        cout << "2. LRU\n";
        cout << "3. Optimal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) break;

        cout << "\nEnter number of pages: ";
        cin >> n;

        pages.resize(n);
        cout << "Enter page reference string: ";
        for (int i = 0; i < n; i++)
            cin >> pages[i];

        cout << "Enter number of frames: ";
        cin >> frameCount;

        switch (choice) {
            case 1: FIFO(pages, frameCount); break;
            case 2: LRU(pages, frameCount); break;
            case 3: Optimal(pages, frameCount); break;
            default: cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    cout << "\nExiting the code!\n";
    return 0;
}
