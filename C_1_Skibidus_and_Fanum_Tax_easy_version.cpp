#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        vector<int> A(n);
        vector<int> B(n);
        for(int i=0;i<n;i++){
            cin >> A[i];

        }
        for(int i=0;i<m;i++){
            cin >> B[i];

        }
        int current = A[0];
        int 
        for(int i=0;i<n;i++){
            A[i] = min(A[i],B[i]-A[i]);
            if(A[i] >= A[i-1]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

            

        }
    }
}

