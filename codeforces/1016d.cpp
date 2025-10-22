#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        while (q--) {
            string op;
            cin >> op;

            if (op == "->") {
                ll x, y;
                cin >> x >> y;
                ll d = 0;

                for (int k = n; k >= 1; --k) {
                    ll half = 1LL << (k - 1);          
                    ll block = 1LL << (2 * (k - 1));   
                    int id;

                    if (x <= half && y <= half) id = 0;        
                    else if (x > half && y > half) id = 1;     
                    else if (x > half && y <= half) id = 2;    
                    else id = 3;                               

                    d += id * block;

                    if (x > half) x -= half;
                    if (y > half) y -= half;
                }

                cout << d + 1 << '\n';
            }

            else { 
                ll d;
                cin >> d;
                d--;
                ll x = 1, y = 1;

                for (int k = n; k >= 1; --k) {
                    ll half = 1LL << (k - 1);
                    ll block = 1LL << (2 * (k - 1));
                    ll id = d / block;
                    d %= block;

                    if (id == 1) { x += half; y += half; }  
                    else if (id == 2) x += half;            
                    else if (id == 3) y += half;            
                }

                cout << x << " " << y << '\n';
            }
        }
    }
    return 0;
}
