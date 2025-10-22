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

bool Allminusones(vector<int> &v){
    for(auto &i: v){
        if(i!=-1)   return 0;
    }
    return 1;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    
    for(int i=0;i<n;i++)    cin>>b[i];
    int ans;
    // when all eles of b are -1 
    if(Allminusones(b)){
        ans = (*min_element(a.begin(),a.end())+k)-(*max_element(a.begin(),a.end()))+1;
        cout<<ans<<endl;
        return;
    } 
    // when the given arr itself is not complementary
    int sum;
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            sum = a[i]+b[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            if(a[i]+b[i]!=sum){
                cout<< 0<<endl;
                return;
            }
        }
    }
    // trying  to fix b
    for(int i=0;i<n;i++){
        if(b[i]==-1){
            int req = sum - a[i];
            if(req > k || req < 0){
                cout<< 0<< endl;
                return;
            }
        }
    }
    cout<< 1<<endl;

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