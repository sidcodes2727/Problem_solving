#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        vector<int> v(m);
        for(int i=0;i<m;i++)
        {
            cin>>v[i];
        }

        vector<int> knows(k);

        for(int i=0;i<k;i++)
        {
            cin>>knows[i];
        }
        vector<int>ans(m);
        if(k==n)
        {
            for(int i=0;i<m;i++)
            {
                ans[i]=1;
            }
        }
        else if(k==n-1)
        {
            int num=1;
            for(auto a:knows)
            {
                if(num== a)
                {
                    num++;
                }

            }
            for(int i=0;i<m;i++)
            {
                if(v[i]==num)
                {
                    ans[i]=1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    
    }
    return 0;
}
