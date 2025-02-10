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
    
    vector<ll> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(b.begin(), b.end()); // Sort b for binary search
    
    // Set the first element optimally
    a[0] = min(a[0], b.back() - a[0]);
    
    for (int i = 1; i < n; i++) {
        ll x = a[i];
        auto it = lower_bound(b.begin(), b.end(), x + a[i - 1]);
        
        if (it != b.end()) {
            ll y = *it - x;
            if (y >= a[i - 1]) {
                a[i] = y;
                continue;
            }
        }
        
        if (x < a[i - 1]) {
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

