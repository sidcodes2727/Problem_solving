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
// int calMed(vector<int> &v){
//     sort(v.begin(),v.end());
//     if(v.size()%2==0)   
// }

bool isValid(vector<int> v){
    set<int> s(v.begin(),v.end());
    if(s.size()>2)  return 0;
    for(auto i:s){
        if(i%2!=0)  return 0;
    }
    return 1;
}
bool allZero(vector<int> v){
    for(auto i:v){
        if(i!=0)    return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int cnt=0;
    for(int i=0;i<n;i++)    cin>>v[i];
    set<int> s;
    vector<int> ans;

    if(allZero(v)){
        cout<<0<<endl;
        cout<<endl;
        return;
    }  
    int k=40;
    while(k--){

        sort(v.begin(),v.end());
        int m=*upper_bound(v.begin(),v.end(),0);
        ans.push_back(m);
        cnt++;
        for(int i=0;i<n;i++)    v[i]=abs(v[i]-m);  
        if(allZero(v))  break;
        if(isValid(v)){
            cnt+=2;
            m=*upper_bound(v.begin(),v.end(),0);
            ans.push_back(m/2);
            ans.push_back(m/2);
            break;
        }  
    }

    if(k==-1){
        cout<<-1<<endl;
        return;
    }   
    cout<<cnt<<endl;
    for(auto i: ans)    cout<<i<<" ";
    cout<<endl;
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