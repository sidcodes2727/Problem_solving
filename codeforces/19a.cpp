#include <bits/stdc++.h>
using namespace std;

bool has_consecutive_threes(int x) {
    string s = to_string(x);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '3' && s[i - 1] == '3') {
            return true;
        }
    }
    return false;
}

void remove_consecutive_threes(int &x) {
    string s = to_string(x);
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '3' && s[i - 1] == '3') {
                s.erase(i - 1, 2);
                changed = true;
                break;
            }
        }
    }
    x = s.empty() ? 0 : stoi(s);
}

string solve(int x) {
    while (x != 0) {
        if (has_consecutive_threes(x)) {
            remove_consecutive_threes(x);
        } else if (x >= 33) {
            x -= 33;
        } else {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}