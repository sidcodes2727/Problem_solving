#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<ll> a(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    int Q;
    cin >> Q;

    vector<ll> add(N + 1, 0);  
    vector<int> stamp(N + 1, 0);
    ll assign_val = 0;
    int ver = 0;     
    bool assigned = false;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            assign_val = x;
            assigned = true;
            ++ver; 
        } else if (t == 2) {
            int i; ll x;
            cin >> i >> x;
            if (assigned) {
                if (stamp[i] != ver) {
                    stamp[i] = ver;
                    add[i] = 0;
                }
                add[i] += x;
            } else {
                a[i] += x;
            }
        } else if (t == 3) {
            int i;
            cin >> i;
            ll res;
            if (assigned) {
                res = assign_val + ((stamp[i] == ver) ? add[i] : 0LL);
            } else {
                res = a[i];
            }
            cout << res << '\n';
        }
    }
    return 0;
}
