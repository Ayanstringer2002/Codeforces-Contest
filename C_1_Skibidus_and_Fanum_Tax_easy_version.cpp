#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll b;
    cin >> b; // Since m = 1, only one element exists in b
    
    // Set the first element optimally
    a[0] = min(a[0], b - a[0]);
    
    for (int i = 1; i < n; i++) {
        ll x = b - a[i];
        ll y = a[i];
        
        // Choose the smallest valid value
        if (min(x, y) >= a[i - 1]) {
            a[i] = min(x, y);
        } else if (max(x, y) >= a[i - 1]) {
            a[i] = max(x, y);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

