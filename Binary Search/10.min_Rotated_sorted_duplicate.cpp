// 154. Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int si = 0;
        int ei = n-1;
        
        while(si < ei){
            int mid = si + (ei-si)/2;
            
            if(arr[mid] < arr[ei]){
                ei = mid;
            }else if(arr[mid] > arr[ei]){
                si = mid+1;
            }else{
                ei--;
            }
        }
        return arr[si];
    }
};