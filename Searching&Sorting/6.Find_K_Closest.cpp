
// Approach 1
class Solution {
public:
    
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int ele : arr){
            
            int val = abs(ele - x);
            pq.push(make_pair(val,ele));
        }
        
        vector<int> ans;
        int i = 0;
        while(i < k){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

// Approach 2

   vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
