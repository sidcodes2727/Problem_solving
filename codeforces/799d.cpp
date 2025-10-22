#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int modpow(int a, int b, int mod = MOD) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
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

string simplify(string s){
    string ans = "";
    for(auto &c: s){
        if(c != ':') ans += c;
    }
    return ans;
}

bool isPalin(string s){
    int l = 0, r = s.length() - 1;
    while(l <= r){
        if(s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

string calculateNext(string s, int x){
    int hours = x / 60;
    int mins = x % 60;

    int givenHour = stoi(s.substr(0, 2));
    int givenMin = stoi(s.substr(3, 2));

    givenMin += mins;
    givenHour = (givenHour + hours + givenMin / 60) % 24;
    givenMin %= 60;

    string hh = (givenHour < 10 ? "0" : "") + to_string(givenHour);
    string mm = (givenMin < 10 ? "0" : "") + to_string(givenMin);

    return hh + ":" + mm;
}

void solve(){
    string s;
    int x;
    cin >> s >> x;

    string temp = s;
    int cnt = 0;

    temp = calculateNext(temp, x); 
    while(temp != s){
        if(isPalin(simplify(temp))) cnt++;
        temp = calculateNext(temp, x);
    }
    if(isPalin(simplify(temp))) cnt++;

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
