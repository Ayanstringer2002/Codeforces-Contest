#include <bits/stdc++.h>
using namespace std;

vector<int> replaceSubarray(int n, int m, vector<int>& v1, vector<int>& v2) {
    int minIndex = min_element(v2.begin(), v2.end()) - v2.begin();
    vector<int> modifiedArr = v1;

    for (int start = 0; start <= n - m; start++) {
        bool shouldReplace = false;
        for (int shift = 0; shift < m; shift++) {
            if (modifiedArr[start + shift] < v2[(shift + minIndex) % m])
                break;
            if (modifiedArr[start + shift] > v2[(shift + minIndex) % m]) {
                shouldReplace = true;
                break;
            }
        }
        if (shouldReplace) {
            for (int shift = 0; shift < m; shift++) {
                modifiedArr[start + shift] = v2[(shift + minIndex) % m];
            }
        }
    }
    return modifiedArr;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sizeA, sizeB;
        cin >> sizeA >> sizeB;
        vector<int> A(sizeA), B(sizeB);

        for (int& elem : A) cin >> elem;
        for (int& elem : B) cin >> elem;

        vector<int> result = replaceSubarray(sizeA, sizeB, A, B);
        int p = result.size();
        
        for (size_t i = 0; i < p; ++i) {
            cout << result[i];
            if (i < p - 1) cout << ' ';
        }
        cout << '\n';
        
    }
    return 0;
}
