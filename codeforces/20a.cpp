#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int open=0;
    int f=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            open++;
        } 
        if(s[i]==')')
        {
            open--;
        }
        if(open==0 && i!=s.length()-1)   f=1; 
    }
    if(f==1)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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