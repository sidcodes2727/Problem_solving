#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> teachers(m);
    for (int i = 0; i < m; i++) {
        cin >> teachers[i];
    }
    int david;
    cin >> david;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, abs(david - teachers[i]));
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}