#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool hasZero = false;
        for (int &x : a) {
            cin >> x;
            if (x == 0) hasZero = true;
        }
        vector<pair<int, int>> ops;
        
        if (hasZero) {
            int curN = n;
            for (int i = 0; i < n && curN > 1;) {
                if (a[i] == 0) {
                    int l = i + 1;      
                    int r = i + 2;     
                    ops.emplace_back(l, r);
                    
                    for (int j = i; j < curN-1; j++) a[j] = a[j+1];
                    curN--;
                    
                } else {
                    i++;
                }
            }
            // After all zeros are gone, combine whole array
            ops.emplace_back(1, curN);
        } else {
            // No zeros: combine all at once
            ops.emplace_back(1, n);
        }
        // Output
        cout << ops.size() << endl;
        for (auto &p : ops) cout << p.first << " " << p.second << endl;
    }
    return 0;
}
