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
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    
    int a3 = a1+a2;
    int ans1=1;
    if(a3+a4==a5)   ans1+=1;
    
    if(a2+a3==a4)   ans1+=1;
    
    int ans2=1;
    a3= a4-a2;
    if(a1+a2==a3)   ans2+=1;
    if(a3+a4==a5)   ans2+=1;

    cout<< max(ans1,ans2)<<endl;

 
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
    
  