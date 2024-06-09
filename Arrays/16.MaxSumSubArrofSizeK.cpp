// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    //Function to find the maximum sum of a subarray of size K.
    long maximumSumSubarray(int K, vector<int> &Arr, int N){
        
        
        long res = 0;
        //Calculating the sum of the first K elements in the array.
        for (int i=0; i<K; i++)
           res += Arr[i];
     
        long curr_sum = res;
        //Iterating over the remaining elements in the array.
        for (int i=K; i<N; i++)
        {
           //Calculating the sum of the current subarray by subtracting the first element
           //of the previous subarray and adding the current element.
           curr_sum += Arr[i] - Arr[i-K];
           //Updating the result with the maximum of the current sum and the previous result.
           res = max(res, curr_sum);
        }
     
        //Returning the maximum sum of a subarray of size K.
        return res;
        
        
        
    }
};