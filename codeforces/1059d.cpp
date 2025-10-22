#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

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
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll query(int t,int l,int r){
    cout<<t<<" "<<l<<" "<<r<<endl;
    cout.flush();
    ll x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    ll total=query(2,1,n)-query(1,1,n);
    int lo=1,hi=n;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(query(2,lo,mid)-query(1,lo,mid)>0) hi=mid;
        else lo=mid+1;
    }
    int l=lo;
    lo=l,hi=n;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(query(2,l,mid)-query(1,l,mid)==mid-l+1) lo=mid;
        else hi=mid-1;
    }
    int r=lo;
    cout<<"! "<<l<<" "<<r<<endl;
    cout.flush();    
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