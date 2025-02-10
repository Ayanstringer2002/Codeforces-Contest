#include<bits/stdc++.h>
using namespace std;
long long calculate_max_score(vector<vector<int>>& arrays){
    int n = arrays.size();
    int m = arrays[0].size();
    for(auto& arr : arrays){
        sort(arr.rbegin(),arr.rend());

    }
    // Sort arrays based on their sum in decreasing order
    sort(arrays.begin(), arrays.end(), [](const vector<int>& a, const vector<int>& b) {
        return accumulate(a.begin(), a.end(), 0LL) > accumulate(b.begin(), b.end(), 0LL);
    });
    
    // Create the final concatenated array
    vector<int> final_array;
    for (const auto& arr : arrays) {
        final_array.insert(final_array.end(), arr.begin(), arr.end());
    }
    
    // Calculate the score
    long long score = 0, prefix_sum = 0;
    for (int num : final_array) {
        prefix_sum += num;
        score += prefix_sum;
    }
    
    return score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> arrays(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arrays[i][j];
            }
        }
        
        cout << calculate_max_score(arrays) << '\n';
    }
    
    return 0;
}
/*
Logic :
i) Sorting Each Array: Each individual array is sorted in decreasing order.
ii) Sorting Arrays by Sum: The arrays are then sorted in decreasing order based on their sum.
iii) Concatenating the Sorted Arrays: A final array is created by concatenating these sorted arrays.
iv) Computing the Score: The score is calculated using prefix sums to ensure optimal computation
*/

/*
Dry run :

Input:
1
2 2
4 4
6 1
Step 1: Sort array in decreasing 
[4, 4] -> remains [4, 4]
[6, 1] -> becomes [6, 1] (already sorted)

Step 2: Sort arrays based on thier summation
Sum of [4, 4] = 8
Sum of [6, 1] = 7
Since 8 > 7, the order remains [4, 4], [6, 1].

Step 3: Concatenating the arrays:
Final array: [4, 4, 6, 1]

Calculating the score using prefix sum:
Prefix sum: 4  → 4
Prefix sum: 4+4=8  → 4 + 8 = 12
Prefix sum: 8+6=14  → 12 + 14 = 26
Prefix sum: 14+1=15  → 26 + 15 = 41

Final score : 41 
*/