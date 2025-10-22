#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> last;         
    vector<int> count(10, 0);  

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= 10;               
        if (count[x] < 3) {     
            last.push_back(x);
            count[x]++;
        }
    }

    bool found = false;
    int sz = last.size();
    for (int i = 0; i < sz && !found; i++) {
        for (int j = i + 1; j < sz && !found; j++) {
            for (int k = j + 1; k < sz && !found; k++) {
                if ((last[i] + last[j] + last[k]) % 10 == 3) {
                    found = true;
                }
            }
        }
    }

    cout << (found ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
