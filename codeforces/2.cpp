#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int beautiful_arr(vector<int> &a)
{
    unordered_map<int,int> mp(0);
    int count=0;

    for(auto t:a)
    {
        mp[t]++;
    }

    for(auto i: mp)
    {
        if (i.second >1)
        {
            count ++;

        }
    }
    return a.size()- count;

    

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int element;
            cin>>element;
            arr.push_back(element);
        }
        
        cout<<beautiful_arr(arr);
        
    }
    
    
return 0;
}