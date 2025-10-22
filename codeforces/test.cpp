#include <bits/stdc++.h>
using namespace std;

int calculateStrength(int s, int e, vector<int>& v)
{
    int mi = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        mi = min(mi, v[i]);
    }
    return mi * (e - s + 1);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> weak;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < x)
        {
            weak.push_back(v[i]);
        }
    }

    int count = n - weak.size(); 

    sort(weak.rbegin(),weak.rend());
    int s = 0, e = 0;

    while (e < weak.size())
    {
        if (calculateStrength(s, e, weak) >= x)
        {
            count++;
            s = e + 1;
        }
        e++;
    }

    cout << count << '\n';
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
