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
    ll n, m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];
    sort(v.begin(),v.end());
    if(m<n){
        ll mul=1;
        ll ans=0;
        for(int i=n-m;i<n;i++){
            ans+=1ll*(mul*v[i]);
            mul++;
        }
        cout<<ans<<endl;
        return;
    }
    ll ans =0;
    ll mul=1;
    while(m!=(n-1)){
        ans += v[0];
        m--;
        mul++;
    }
    for(int i=1;i<n;i++){
        ans+=1ll*(mul*v[i]);
        mul++;
    }
    cout<<ans<<endl;
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