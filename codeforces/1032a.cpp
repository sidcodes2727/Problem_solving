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
        int n,s;
        cin>>n>>s;
        vector<int> v(n);
        for(int i=0;i<n;i++)    cin>>v[i];
        if(n==1){
            cout<<abs(s-v[0])<<endl;
            return;
        }

        sort(v.begin(),v.end());
        if(v[n-1]<s){
            cout<<s-v[0]<<endl;
            return;
        }
        if(v[0]>s){
            cout<<v[n-1]-s<<endl;
            return;
        }
        int x1=abs(v[n-1]-s);
        int x2=abs(v[0]-s);
        cout<< max(x1,x2)+2*min(x1,x2)<<endl;

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