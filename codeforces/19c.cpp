#include <bits/stdc++.h>
using namespace std;

vector<int> thirteen = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 13, 12, 12, 1, 13};

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        for (int i = 1; i <= (n / 2); i++)
        {
            cout << i << " " << i<< " ";
        }
        cout << endl;
    }
    else if (n < 27 && n % 2 != 0)
    {
        cout << -1 <<endl;
    }
    else
    {
        vector<int> ans = thirteen;
        int left = n - 27;
        for (int i = 1, j = 14; i <= left; i += 2, j++)
        {
            ans.push_back(j);
            ans.push_back(j);
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
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
