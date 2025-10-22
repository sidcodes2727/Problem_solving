#include <bits/stdc++.h>
using namespace std;

int scoreFunc(vector<int> a, vector<int> b, int k) {
    int score = 0;
    int n = a.size() - 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] + k < b[i]) {
            swap(a, b); 
            
        }
        score += a[i];
        
        
    }
    return score;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), b(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int q;
    cin >> q;
    vector<vector<int>> Q(q, vector<int>(3));
    for (int i = 0; i < q; i++)
        for (int j = 0; j < 3; j++)
            cin >> Q[i][j];

    for (int i = 0; i < q; i++) {
        int t = Q[i][0], p = Q[i][1], x = Q[i][2];
        if (t == 1) {
            a[p] = x;
        } else if (t == 2) {
            b[p] = x;
        }
        cout << scoreFunc(a, b, k) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
