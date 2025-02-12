#include<bits/stdc++.h>
using namespace std;
void coolsequence(){
    int N;
    cin >> N;
    vector<int> V1(N);
    for(int i=0;i<N;i++){
        cin >> V1[i];
        
    }
    unordered_set<int> phaset;
    for(int i=0;i<N;i++){
        phaset.insert(V1[i]);
        
    }
    unordered_map<int,int> mpp2;
    for(int val : V1){
        mpp2[val]++;
        if(mpp2[val] > 1){
            cout << "1\n" << val << "\n";
            return;
        }
    }
    cout << "-1\n";
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        coolsequence();
    }
    
    return 0;
}
