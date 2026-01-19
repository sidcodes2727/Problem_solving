//sidcodes
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
typedef vector<vll> vvll;

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


ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

vector<ll> fact, invfact;

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void init_nck(int maxn){
    fact.assign(maxn+1, 1);
    invfact.assign(maxn+1, 1);

    for(int i = 1; i <= maxn; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    invfact[maxn] = modpow(fact[maxn], MOD - 2);

    for(int i = maxn-1; i >= 0; i--)
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
}

ll nck(ll n, ll r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % MOD) * invfact[n-r]) % MOD;
}


vector<vll> adj; 
vll depth, parent, sub;
vector<vll> dp;     



// its like diff arr

// ll lca(ll a,ll b){
//     while(a!=b){
//         if(depth[a]<depth[b]){
//             b=parent[b];
//         }
//         else{
//             a=parent[a];
//         }
//     }
//     return a;
// }
// up[u][i]= the 2^i th ancestor of u
const int LOG = 20;
vvll up;
void dfs(ll u, ll p) {
    parent[u] = p;
    // sub[u] = 1;
    up[u][0]=p;
    for(int i=1;i<LOG;i++){
        if(up[u][i-1]==-1)  up[u][i]=-1;
        else    up[u][i]=up[up[u][i-1]][i-1];
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        // sub[u] += sub[v];
    }
}
int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);        // assume u is deeper than v

    // 1) lift u to same depth as v
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++){
        if(diff & (1 << i)){
            u = up[u][i];
        }
    }

    if(u == v) return u;

    // 2) lift both up until parents differ
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != -1 && up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    // 3) now parents are same
    return parent[u];
}
ll distance(ll a,ll b){
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}
void dfs2(ll node,ll p,vll &ans){
    for(auto ch:adj[node]){
        if(ch==p)   continue;
        dfs2(ch,node,ans);
        ans[node]+=ans[ch];
    }
}
void solve() {
    ll n,m;
    cin>>n>>m;
    adj.assign(n+1,vll());
    parent.assign(n+1,-1);
    depth.assign(n+1,0);
    up.assign(n+1,vll(LOG,-1));
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    vll ans(n+1,0);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        ll l=lca(a,b);
        ans[a]++;
        ans[b]++;
        ans[l]--;
        if(parent[l]!=-1)  ans[parent[l]]--;
    }
    dfs2(1,-1,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}