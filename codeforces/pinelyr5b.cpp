#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (v[i][j] == '#' && v[i][j - 1] == '#' && v[i][j - 2] == '#') {
                cout << "NO\n";
                return;
            }
        }
    }

    
    for (int j = 0; j < n; j++) {
        for (int i = 2; i < n; i++) {
            if (v[i][j] == '#' && v[i - 1][j] == '#' && v[i - 2][j] == '#') {
                cout << "NO\n";
                return;
            }
        }
    }

    
    vector<vector<char>> up;
    for (auto &row : v) {
        bool allDot = true;
        for (auto c : row)
            if (c != '.') { allDot = false; break; }
        if (!allDot) up.push_back(row);
    }

    int k = up.size();
    if (k == 0) { 
        cout << "YES\n";
        return;
    }

    int m = up[0].size();

    
    for (int i = 0; i < k; i++) {
        for (int j = 2; j < m; j++) {
            if (up[i][j - 2] == '#' && up[i][j] == '#') {
                bool below = (i + 1 < k) && 
                    (up[i + 1][j] == '#' || up[i + 1][j - 1] == '#' || up[i + 1][j - 2] == '#');
                bool above = (i - 1 >= 0) && 
                    (up[i - 1][j] == '#' || up[i - 1][j - 1] == '#' || up[i - 1][j - 2] == '#');
                if (above || below) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    
    for (int j = 0; j < m; j++) {
        for (int i = 2; i < k; i++) {
            if (up[i - 2][j] == '#' && up[i][j] == '#') {
                bool right = (j + 1 < m) &&
                    (up[i][j + 1] == '#' || up[i - 1][j + 1] == '#' || up[i - 2][j + 1] == '#');
                bool left = (j - 1 >= 0) &&
                    (up[i][j - 1] == '#' || up[i - 1][j - 1] == '#' || up[i - 2][j - 1] == '#');
                if (left || right) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
