#include <bits/stdc++.h>
using namespace std;

void coolSubsequence(int n, const vector<int>& a) {
    unordered_map<int, int> frequency;

    // Count occurrences using iterators
    for (auto it = a.begin(); it != a.end(); ++it) {
        frequency[*it]++;
    }

    // Check for elements appearing at least twice using iterators
    for (auto it = frequency.begin(); it != frequency.end(); ++it) {
        if (it->second >= 2) {
            cout << "1\n" << it->first << "\n";
            return;
        }
    }

    // If no duplicate elements found
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (auto it = a.begin(); it != a.end(); ++it) {
            cin >> *it;
        }

        coolSubsequence(n, a);
    }

    return 0;
}
