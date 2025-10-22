#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(const vector<ll> &a, ll k) {
    int n = a.size();
    int unpaired = 0;
    int i = 0;
    while (i < n) {
        if (i + 1 < n && a[i + 1] - a[i] <= k) {
            i += 2; 
        } else {
            unpaired++;
            if (unpaired > 1) return false; 
            i += 1; 
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        ll low = 0, high = 1e18, ans = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (isValid(a, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
