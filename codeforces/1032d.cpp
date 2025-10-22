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

void bubbleSort(vector<int> &arr, int n, int &k, vector<pair<int,int>> &ops, int num) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {  
                k++;
                ops.push_back({num, j + 1}); 
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int k = 0;
    vector<pair<int,int>> ops;

    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            k++;
            ops.push_back({3, i + 1}); 
            swap(a[i], b[i]);
        }   
    }

    bubbleSort(a, n, k, ops, 1);
    bubbleSort(b, n, k, ops, 2);

    cout << k << "\n";
    for(auto &i: ops) {
        cout << i.first << " " << i.second << "\n";
    }
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