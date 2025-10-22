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

void solve(){
    int n;
        cin >> n;
        vector<long long> b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> b[i];
        vector<int> a(n + 1);     
        vector<int> last(n + 2);  
        long long prev = 0;
        int ni = 1;
        for (int i = 1; i <= n; ++i) {
            long long diff = b[i] - prev;
            prev = b[i];

            if (diff == i) {
                a[i] = ni;
                last[i] = ni;
                ni++;
            } else {
                int pos = i - diff;
                a[i] = last[pos];
                last[pos] = 0;  
                last[i] = a[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << endl;
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