
#include <bits/stdc++.h>


// ---------------------------(SIMPLIFIED)-------------------------------

// Made a frequency map to store number of occurance of all elements.
// The most appearing elements count will decide the number of row in answer vector.
// If we have a element appearing twice then will run a loop to push it in 2 rows, similarly done for all.


/*


Approach 1
Frequency Calculation: The code starts by creating an unordered map um to count the frequency of each element in the input vector v. The frequency map stores the count of occurrences of each unique element.

Creating the Resultant Matrix: The code proceeds to create the resultant matrix ans. It loops until the frequency map um becomes empty.

Constructing Rows of the Matrix: Within each iteration of the loop, it initializes a temp vector to store elements for a row. Then, it iterates through the frequency map um, adding elements to temp and decreasing their count in the map. If an element's count becomes zero, it is added to the toErase vector.

Adding Rows to the Matrix: Once a row (temp) is constructed, it is appended to the ans matrix. After constructing a row, elements that have a count of zero are removed from the frequency map (um) using the toErase vector.

Repeat Until Map is Empty: This process continues until the frequency map um becomes empty, and at each step, it constructs a row based on the available counts of elements.

Return the Result: Finally, it returns the resultant matrix ans, which contains rows of integers based on their frequency counts from the input vector v.

Complexity
Time complexity:
O(n^2)

Space complexity:
O(n)
*/


//2610. Convert an Array Into a 2D Array With Conditions
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cnt =0;

        for(auto a:nums){
            mp[a]++;
            cnt = max(cnt,mp[a]);
        }
        vector<vector<int>>v(cnt);
        for(auto a: mp){
            int num = a.first;
            int freq = a.second;

            for(int i =0;i<freq;i++){
                v[i].push_back(num);
            }
        }
        return v;
        
    }
};