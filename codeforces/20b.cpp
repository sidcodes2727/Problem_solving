#include <bits/stdc++.h>
using namespace std;

void mex(int &i, vector<int> &arr)
{
    
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // We'll always do n-1 operations: merge positions 1 and 2, then 1 and 2 again, etc.
    cout << n - 1 << endl;
    for (int i = 1; i < n; i++) {
        cout << 1 << " " << 2 << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}