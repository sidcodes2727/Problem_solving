#include <bits/stdc++.h>
using namespace std;
string solve(vector<int> &v,int k)
{
    int m= v[k-1];
    sort(v.begin(),v.end());
    int i;

    for(i=0;i<v.size();i++)
    {
        if(v[i]==m)
        {
            break;
        }
    }
    int water =1;
    while(i < v.size()-1)
    {
        if(v[i+1]>= water+v[i+1]-v[i] && v[i]>= water+v[i+1]-v[i]-1)
        {
            water= water +v[i+1]-v[i];
            i++;
        }
        else {
            break;
        }



    }
    if(i==v.size()-1)  
    {return "yes";}

    else{

    return "no";
    }

    return 0;
    

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << solve(v,k)<<endl;
    }
    return 0;
}
