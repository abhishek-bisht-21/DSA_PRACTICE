// 852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int si = 0;
        int ei = n-1;
        
        while(si < ei){
            int mid = (si+ei)/2;
            // If the mid is in the increasing sequence then move towards right
            if(arr[mid] < arr[mid+1]){
                si = mid+1;
            }else{
                ei = mid;
            }
        }
        
        return si;
    }
};