#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int modpow(int a, int b, int mod = MOD) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> sieve(int n) {
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= n; i++)
        if (isPrime[i])
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = 0;
    return isPrime;
}

void solve(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++)    cin>>b[i];
    map<int,int> mp;
    for(auto &i: b) mp[i]++;

    int uniq = mp.size();

    cout<<uniq<<endl;

    // int ans=INT_MIN;
    // for(int i=0;i<n;i++){
    //     int cnt=1;
    //     int prev = b[i];
    //     int j=(i+1)%n;
    //     while(1){
    //         if(j==i)    break;
    //         if(b[j] > prev){
    //             cnt++;
    //             prev=b[j];
    //         }  
            
    //         j=(j+1)%n;  
    //     }
    //     ans = max(ans , cnt);
    // }
    // cout<<ans<<endl;
    
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