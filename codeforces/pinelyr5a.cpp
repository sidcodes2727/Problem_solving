#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (s[j] == '1') {
            ans++;
            r = max(0, r - d);
        }
        else if (s[j] == '2') {
            if (r < x) {
                ans++;
                r = max(0, r - d);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
