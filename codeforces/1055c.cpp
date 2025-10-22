#include <iostream>
#include <vector>
using namespace std;

long long triple_removal_cost(const vector<int>& a) {
    // Group 0 and 1 indices separately
    vector<int> zeros, ones;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == 0)
            zeros.push_back(i);
        else
            ones.push_back(i);
    }
    if (zeros.size() % 3 != 0 || ones.size() % 3 != 0)
        return -1;

    long long ans = 0;
    auto calc = [&](const vector<int>& v) -> long long {
        long long cost = 0;
        for (size_t i = 0; i + 2 < v.size(); i += 3) {
            cost += min(v[i + 1] - v[i], v[i + 2] - v[i + 1]);
        }
        return cost;
    };

    ans += calc(zeros);
    ans += calc(ones);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        while (q--) {
            int l, r; cin >> l >> r;
            l--, r--;
            vector<int> sub(a.begin() + l, a.begin() + r + 1);
            cout << triple_removal_cost(sub) << "\n";
        }
    }
    return 0;
}
