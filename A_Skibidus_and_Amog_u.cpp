#include<bits/stdc++.h>
using namespace std;

string convertToPlural(const string &singular) {
    return singular.substr(0, singular.size() - 2) + "i";
}

int main() {
    int t;
    cin >> t;
    vector<string> results;
    
    while (t--) {
        string w;
        cin >> w;
        results.push_back(convertToPlural(w));
    }
    
    for (const string &plural : results) {
        cout << plural << "\n";
    }
    
    return 0;
}
