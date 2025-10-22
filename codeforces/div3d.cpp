#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> v(n, vector<int>(3));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> v[i][j];
            }
        }

        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        // cout << "After sorting by 3rd element:\n";
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int x = k;

        for (int i = 0; i < n; i++)
        {
            if (x >= v[i][0] && x <= v[i][1] && v[i][2] > x)
            {
                x=v[i][2];
            }
        }

        cout<<x<<endl;
    }
    return 0;
}