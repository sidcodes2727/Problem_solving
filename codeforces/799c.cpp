#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int modpow(int a, int b, int mod = MOD) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> sieve(int n) {
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
    return isPrime;
}

void solve() {
    vector<vector<char>> v(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (v[i][j] == '#') {
                if (v[i - 1][j - 1] == '#' && v[i - 1][j + 1] == '#' &&
                    v[i + 1][j - 1] == '#' && v[i + 1][j + 1] == '#') {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
