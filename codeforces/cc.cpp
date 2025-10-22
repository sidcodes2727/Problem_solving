#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(v[i]==1 && n== i+1)
	        {
	            cout<<i+1<<endl;
	        }
	        
	        else if(v[i]==n)
	        {
	            cout<<n<<endl;
	        }
	        
	    }
	    
	    
	}
	return 0;

}
