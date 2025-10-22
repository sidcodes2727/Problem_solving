#include<bits/stdc++.h>
using namespace std;

bool isvalid(int arr[],int s, int e){

    for(int i=s;i<=e;i++)
    {
        if(arr[i]==1)
        {
            return false;
        }
    }
    return true;

}
int solve(int arr[],int n, int k)
{
    int s=0;
    int e=k-1;
    int count=0;

    while(e < n)
    {
        if(isvalid(arr,s,e))
        {
            count++;
            s= e+2;
            e= s+(k-1);
        }
        else
        {
            s++;
            e=s+(k-1);
        }

    }
    return count;



}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        cout<<solve(arr,n,k)<<endl;    

    }
    return 0;
}
 
