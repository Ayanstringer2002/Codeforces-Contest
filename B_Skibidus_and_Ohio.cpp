#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string st1;

        cin >> st1;
        int result = st1.size();
        for(int i = 0; i < st1.size() - 1; i++){
            if(st1[i] == st1[i + 1]){
                result = 1;
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}
