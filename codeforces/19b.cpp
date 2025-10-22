#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while( t--)
    {
        int n , m, q;
        cin>>n>>m>>q;
        vector<int> arr (m);

        for(int i=0; i<m; i++)
        {
            cin>>arr[i];
        }
        sort ( arr.begin(), arr.end());

        for(int i=0; i<q; i++)
        {
            int x;
            cin>>x;

            auto right = lower_bound(arr.begin(), arr.end(), x)- arr.begin()  ;

            int left = right - 1;
            if( right == m)
            {
                cout<< n- arr[right-1] << endl;
            }
            else if(left < 0)
            {
                cout<< arr[right] -1  << endl;
            }
            else
            {
                int dl= x-arr[left];
                int dr= arr[right] - x;
                cout<< abs (dl-dr)/2 + min(dl, dr) << endl; 
            }
        }
    }
    return 0;

}