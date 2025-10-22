#include<bits/stdc++.h>
using namespace std;

int calculateStrength(int s, int e,vector<int>  v)
{
    if(v.size()==1)
    {
        return v[s];
    }
    int mi =INT_MAX;
    for(int i=s;i<=e;i++)
    {
        mi=min(mi, v[i]);
    }
    return mi*(e-s+1);
}

void solve()
{
    int n,x;
    cin>>n>>x;
    int count=0;
    vector<int> skills(n);

    for(int i=0;i<n;i++)
    {
        cin>>skills[i];

    }
    sort(skills.begin(),skills.end());
    int s=0;
    int e=0;
    while(e<skills.size())
    {
        if(calculateStrength(s,e,skills)>=x)
        {
            count++;
            s=e+1;
            e++;
        }
        else
        {
            e++;
        }

    }
    cout<<count<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();

    }
    return 0;
}