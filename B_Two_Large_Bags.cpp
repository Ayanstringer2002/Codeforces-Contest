#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m = n + n/2;
        vector<int> freq(m+1,0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            freq[x]++;

        }
        int maxcarry = 2*n;
        vector<vector<bool>> dp(m+2,vector<bool>(maxcarry +1,false));
        dp[1][0] = true;
        for(int x = 1;x<=m;x++){
            for(int carry = 0;carry<=maxcarry;carry++){
                if(!dp[x][carry]) continue;
                int F = freq[x] + carry;
                for(int k = 0; k<=F;k++){
                    int rem = F - k;
                    if(rem % 2 != 0) continue;
                    if(k > 0 && rem < 2) continue;
                    if(k <= maxcarry){
                        dp[x+1][k] = true;

                    }
                }
        
            }
        }
        if(dp[m+1][0]){
            cout << "YES" << endl;

        }else{
            cout << "NO" << endl;
        }
    }
}