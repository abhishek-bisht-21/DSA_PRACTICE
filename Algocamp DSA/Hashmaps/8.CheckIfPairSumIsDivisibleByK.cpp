// Check if Array Pairs are Divisible by K 

/*
If a Pair whose sum must be divisble by K, Then They should be of the nature : Kn+x and Km+(k-x)
    K
  /   \
x     k-x

1)Case 1:  On getting divided by K if a number leaves a remainder x , then other number must leave remainder
k-x. They both should have same frequency

2) Case 2: Both number is getting divided by K. Then their sum will also get divided by K. Leaves Rem
as 0. They should have even frequency

3) Case 3: Numbers which leave k/2. They should also have even frequency
**/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m; // Frequency of Remainders
        for(int ele:arr){
            int rem = ele % k;
            if(rem < 0){
                rem+=k;
            }
            m[rem]++;
        }

        for(int ele: arr){
            int rem = ele % k;

            if(rem == 0){
                int freq = m[rem];
                if(freq%2==1){
                    return false;
                }
            }

            else if(rem * 2 == 0){
                int freq = m[rem];
                if(freq%2==1){
                    return false;
                }
            }else{
                int freq = m[rem];
                int ofq = m[k-rem];

                if(freq != ofq){
                    return false;
                }
            }
        }

        return true;
    }
};