#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

const int MOD = 1e9+7;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(int a, int b) { return (a / gcd(a, b)) * b; }

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



void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = -1;
    for (ll x = 2; x <= 100; x++) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (gcd(v[i], x) == 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans = x;
            break;
        }
    }
    if (ans == -1) {
        for (ll x = 101; x <= 200; x++) {
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (gcd(v[i], x) == 1) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                ans = x;
                break;
            }
        }
    }
    cout << ans << endl;
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