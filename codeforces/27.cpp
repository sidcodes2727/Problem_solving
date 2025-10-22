#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int a = 0, b = 1;
    int min_diff = abs(v[0] - v[1]);

  
    for(int i = 1; i < n; i++) {
        int diff = abs(v[i] - v[(i+1)%n]); 
        if(diff < min_diff) {
            min_diff = diff;
            a = i;
            b = (i + 1) % n;
        }
    }

   
    cout << a + 1 << " " << b + 1 << "\n";
}

int main() {
    fastIO();
    solve(); 
    return 0;
}
