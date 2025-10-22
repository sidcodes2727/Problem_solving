#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int k, x;
    cin>>k>>x;
    int cakes = modpow(2,k);
    int req= x*2;
    int c1= cakes;
    int c2= cakes;
    vector<int> seq;
    int n = 0;
    if(c1==x){
        cout<<0<<endl;
        return;
    }
    if(x < cakes){
        int limit = 120; 
        while(c1!=req && limit--){
            seq.push_back(2);
            c1 += c2/2;
            c2/=2;
            n++;
            if(c1 == req){
                seq.push_back(1);
                n++;
                c1/=2;
                break;
            }
        }
    }
    else{
        int limit = 120; 
        while(c1 != x && limit--){
            if(c1+ c2/2 == x){
                seq.push_back(2);
                n++;
                break;
            }
            seq.push_back(1);
            n++;
            c2+= c1/2;
            c1/=2;
        }
    }
    cout<<n<<endl;
    if(n!=0){
        for(int i=0;i<seq.size();i++)   cout<<seq[i]<<" ";
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--){
      solve();
    }
}
