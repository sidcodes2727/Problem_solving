#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

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
void _print(unsigned long long t) {cerr << t;}
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> ans(n, -1);
    vector<bool> mi(n, 0);
    vector<bool> mex(n, 0);

    vector<pair<int, pair<int, int>>> que(q);

    for (int i = 0; i < q; i++) {
        int c, l, r;
        cin >>c>>l>>r;
        l--; 
        r--; 
        que[i] = {c, {l, r}};
        if (c == 1) {
            for (int j = l; j <= r; j++) mi[j] = 1;
        } else {
            for (int j = l; j <= r; j++) mex[j] = 1;
        }
    }

    vector<pair<int, int>> nk;
    for (auto i : que) {
        if (i.first == 1) { 
            int l = i.second.first;
            int r = i.second.second;  
            bool fnd = 0;
            for (int j = l; j <= r; j++) {
                if (ans[j] == k) { fnd = 1; break; }
            }
            if (!fnd) nk.push_back({r, l}); 
        }
    }
    sort(nk.begin(), nk.end());
    for (auto p : nk) {
        int r = p.first;
        int l = p.second;
        bool fnd = 0;
        for (int j = l; j <= r; j++) {
            if (ans[j] == k) { fnd = 1; break; }
        }
        if (fnd) continue;
  
        for (int j = r; j >= l; j--) {
            if (ans[j] == -1 && mex[j] == 0) {
                ans[j] = k;
                break;
            }
        }
    }
    for (int val = 0; val < k; val++) {
        vector<pair<int, int>> nv;
        for (auto i : que) {
            if (i.first == 2) { 
                int l = i.second.first;
                int r = i.second.second;
                
                bool fnd = 0;
                for (int j = l; j <= r; j++) {
                    if (ans[j] == val) { fnd = 1; break; }
                }
                if (!fnd) nv.push_back({r, l});
            }
        }

        sort(nv.begin(), nv.end());
        for (auto p : nv) {
            int r = p.first;
            int l = p.second;
            
            bool fnd = 0;
            for (int j = l; j <= r; j++) {
                if (ans[j] == val) { fnd = 1; break; }
            }
            if (fnd) continue;  
            for (int j = r; j >= l; j--) {
                if (ans[j] == -1 && mi[j] == 0) {
                    ans[j] = val;
                    break;
                }
            }
        }
    }

    for (auto &i : ans) {
        if (i == -1) i = k+1; 
    }

    for (auto i : ans) cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}