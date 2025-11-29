#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define fr(i,n) for(int i=0;i<n;i++)
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

const int MOD = 1e9+7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(long long t) {cerr << t;}
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);

template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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

struct Matrix {
    ll a[2][2];
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    C.a[0][0] = (A.a[0][0]*B.a[0][0] + A.a[0][1]*B.a[1][0]) % MOD;
    C.a[0][1] = (A.a[0][0]*B.a[0][1] + A.a[0][1]*B.a[1][1]) % MOD;
    C.a[1][0] = (A.a[1][0]*B.a[0][0] + A.a[1][1]*B.a[1][0]) % MOD;
    C.a[1][1] = (A.a[1][0]*B.a[0][1] + A.a[1][1]*B.a[1][1]) % MOD;
    return C;
}

Matrix power(Matrix M, ll n) {
    Matrix R = {{{1, 0}, {0, 1}}}; // identity
    while(n){
        if(n & 1) R = multiply(R, M);
        M = multiply(M, M);
        n >>= 1;
    }
    return R;
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
    ll n;
    cin >> n;
    vector<ll> v(n * 2);
    map<ll, ll> mp;
    for(int i = 0; i < n * 2; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<ll> req;
    for(auto i : mp) req.push_back(i.second);
    sort(req.rbegin(), req.rend());
    
    ll s1 = 0;
    ll s2 = 0;
    ll ans = 0;
    for(auto x : req) {
        if(x % 2 != 0) {
            ans++;
            if(s1 <= s2) {
                s1 += (x - 1);
                s2 += 1;
            } else {
                s2 += (x - 1);
                s1 += 1;
            }
        } 
        else {
            ll min_k = max(1LL, x - (n - s2));
            ll max_k = min(x - 1, n - s1);
            ll k = -1;
            if(min_k <= max_k) {
                if(min_k % 2 != 0) k = min_k; 
                else if(min_k + 1 <= max_k) k = min_k + 1;
            }

            if(k != -1) {
                ans += 2;
                s1 += k;
                s2 += (x - k);
            } else {
                ll take = min(n - s1, x);
                s1 += take;
                s2 += (x - take);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}