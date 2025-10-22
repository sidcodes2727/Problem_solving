#include<bits/stdc++.h>
using namespace std;

void solve(){   
    int n;
    cin>>n;
    int ans;
    if((n+1) % 3 == 0)    ans=1;
    else if(n % 3 == 0) ans=0;
    else if((n+2) % 3 == 0) ans=2;

    cout<< ans <<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
    {
      solve();
    }
}
    
  