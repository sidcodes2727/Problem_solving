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
    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];
    map<int,int> mp;
    for(auto &i:v)  mp[i]++;
    vector<int>o;
    vector<int>e;

    for(auto i: mp){
        int cnt = i.second/2;
        for(int j=0;j<cnt;j++)  e.push_back(i.first);
        if(i.second%2 ==1)  o.push_back(i.first);
    }

    if(e.size()==0){
        cout<<0<<endl;
        return;
    }
    vector<int> s;
    int ans =0;

    for(auto i:e)   ans+= (2*i);
    if(!o.empty())    ans+= *max_element(o.begin(),o.end());

    for(auto &i: e){
        s.push_back(i);
        s.push_back(i);
    }
    int mx = *max_element(o.begin(),o.end());
    if(!o.empty())  s.push_back(mx);
    
    int second=INT_MIN;
    if(o.size()>1){
        for(auto i: o){
            if(i!=mx){
                second = max(second,i);
            }
        }
    }
    if(second!= INT_MIN){
        s.push_back(second);
        ans+=second;
    }

    sort(s.rbegin(),s.rend());
    int sum=0;
    for(int i=1;i<s.size();i++){
        sum+= s[i];
    }
    if(s.size()<3 || s[0]>= sum){
        cout<< 0<<endl;
        return;
    }

    cout<< ans<<endl;

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