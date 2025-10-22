#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum < s) {
        cout << -1 << "\n";
        return;
    }
    if (sum == s) {
        cout << 0 << "\n";
        return;
    }

    int l = 0, curr = 0, maxlen = 0;
    for (int r = 0; r < n; r++) {
        curr += v[r];
        while (curr > s) curr -= v[l++];
        if (curr == s) maxlen = max(maxlen, r - l + 1);
    }

    cout << n - maxlen << "\n"; 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
