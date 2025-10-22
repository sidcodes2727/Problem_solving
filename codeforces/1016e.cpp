#include <bits/stdc++.h>
using namespace std;


bool canAchieve(const vector<int>& a, int n, int k, int x) {
    vector<int> cnt(x + 1, 0); 
    int cur_mex = 0;
    int segments = 0; 

    for (int i = 0; i < n; i++) {
        if(a[i] <= x) cnt[a[i]]++;

        while(cur_mex <= x && cnt[cur_mex] > 0) cur_mex++; 

        
        if(cur_mex >= x) {
            segments++;             
            fill(cnt.begin(), cnt.end(), 0); 
            cur_mex = 0;            
        }
    }

    return segments >= k; 
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n + 1, ans = 0;

    
    while(l <= r) {
        int mid = (l + r) / 2;
        if(canAchieve(a, n, k, mid)) {
            ans = mid;
            l = mid + 1; 
        } else {
            r = mid - 1; 
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
