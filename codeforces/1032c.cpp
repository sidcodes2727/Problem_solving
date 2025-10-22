#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int mx = 0, cnt_mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] > mx) {
                    mx = a[i][j];
                    cnt_mx = 1;
                } else if (a[i][j] == mx) {
                    cnt_mx++;
                }
            }
        }
        vector<int> rowCount(n, 0), colCount(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == mx) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
10
        bool canReduce = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int totalCovered = rowCount[i] + colCount[j];
                if (a[i][j] == mx) totalCovered--; 
                if (totalCovered == cnt_mx) {
                    canReduce = true;
                    break;
                }
            }
            if (canReduce) break;
        }

        
        cout << mx - canReduce << '\n';
    }

    return 0;
}
