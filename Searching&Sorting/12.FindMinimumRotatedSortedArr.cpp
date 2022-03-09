class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int si = 0;
        int ei = n-1;
        
        while(si < ei){
            int mid = (si+ei)/2;
            
            if(arr[mid] < arr[ei]){
                ei = mid;
            }else{
                si = mid+1;
            }
        }
        
        return arr[si];
    }
};