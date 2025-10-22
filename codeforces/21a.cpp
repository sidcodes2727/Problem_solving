#include <bits/stdc++.h>
using namespace std;

bool check(unordered_map<int, int> &mp)
{
    for (auto m : mp)
    {
        if (m.second > 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    unordered_map<int, int> mp = {{0, 3}, {1, 1}, {2, 2}, {3, 1}, {5, 1}};

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]--;
        count++;
        if (check(mp))
        {
            cout << count << endl;
            return;
        }
    }

    cout << 0 << endl;
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
