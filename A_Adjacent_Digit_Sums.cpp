#include <bits/stdc++.h>
using namespace std;

bool is_valid(int n1, int n2) {
    return (n1 + 1 - n2) >= 0 && (n1 + 1 - n2) % 9 == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1, n2;
        cin >> n1 >> n2;
        cout << (is_valid(n1, n2) ? "YES" : "NO") << endl;
    }
    return 0;
}