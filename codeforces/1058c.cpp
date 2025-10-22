#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

const int MOD = 1e9+7;
const int INF = 1e9;
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
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i];

        vector<vector<int>> res(n, vector<int>(m, INF));

        for(int u = 0; u < n-1; u++) {
            vector<int> common(m, 0);
            for(int d = u+1; d < n; d++) {
                vector<int> cols;
                for(int j = 0; j < m; j++) {
                    if(grid[u][j] == '1' && grid[d][j] == '1') {
                        cols.push_back(j);
                    }
                }

                for(int k = 0; k+1 < cols.size(); k++) {
                    int l = cols[k];
                    int r = cols[k+1];
                    int area = (d-u+1)*(r-l+1);
                    for(int i = u; i <= d; i++)
                        for(int j = l; j <= r; j++)
                            res[i][j] = min(res[i][j], area);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == INF) cout << 0;
                else cout << res[i][j];
                if(j+1 < m) cout << " ";
            }
            cout << "\n";
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    w10
}