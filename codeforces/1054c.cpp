#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Count how many times k appears
    int cnt = 0;
    for (auto &i : v) {
        if (i == k) cnt++;
    }

    // Track which numbers appear
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; i++) {
        if (v[i] <= n) visited[v[i]] = true;
    }

    // Count missing numbers in [0 .. k-1]
    int req = 0;
    for (int i = 0; i < k; i++) {
        if (!visited[i]) req++;
    }

    // Answer = max(missing, count of k’s)
    cout << max(req, cnt) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
