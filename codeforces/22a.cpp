#include <bits/stdc++.h>
using namespace std;

// void more(string &s, int i, char c, int &count)
// {
//     for (int k = i; k < i + 3; k++)
//     {
//         if (s[k] == c)
//         {
//             count++;
//         }
//     }
// }

void solve()
{
    int n;
    cin >> n;
    string s;
    
        cin >> s;


    int count = 0;
    for (int i = 0; i < n - 2;)
    {
        if (s.substr(i, 3) == "pie" || s.substr(i, 3) == "map")
        {
            i+=3;
            count++;
        }
        else
        {
            i++;
        }

        
    }
    cout << count << endl;
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