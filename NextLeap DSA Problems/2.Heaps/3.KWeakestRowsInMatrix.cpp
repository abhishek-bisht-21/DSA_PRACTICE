//1337. The K Weakest Rows in a Matrix

// Approach 1:

class Solution {
public:

    int lastOccurence(vector<int> &arr){
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == 1){
                ans = mid;
                start++;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }

    struct CompareHeapElement {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

         priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElement> soldier_count;
         for(int i=0;i<mat.size();i++){
             int count = lastOccurence(mat[i]) + 1;
              soldier_count.push({count,i});
             if(soldier_count.size() > k)
                soldier_count.pop();
         }

         vector<int> ans;

         for(int i=0;i<k;i++){
             ans.push_back(soldier_count.top().second);
             soldier_count.pop();
         }  

         reverse(ans.begin(), ans.end());   
         return ans;
    }
};

// Approach 2:

class Solution {
public:

    int lastOccurence(vector<int> &arr){
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == 1){
                ans = mid;
                start++;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

         vector<pair<int,int>> soldier_count;
         for(int i=0;i<mat.size();i++){
             int count = lastOccurence(mat[i]) + 1;
             soldier_count.push_back({count,i});
         }

         sort(soldier_count.begin(), soldier_count.end());

         vector<int> ans;

         for(int i=0;i<k;i++){
             ans.push_back(soldier_count[i].second);
         }  

         return ans;
    }
};

// Approach 3

class Solution {
public:

    int lastOccurence(vector<int> &arr){
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == 1){
                ans = mid;
                start++;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }

 
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

         set<pair<int,int>> soldier_count;
         for(int i=0;i<mat.size();i++){
             int count = lastOccurence(mat[i]) + 1;
             soldier_count.insert({count,i});
         }

           vector<int> ans;
        // first k weakest row is our answer 
        for(auto i : soldier_count)
        {
            if(k == 0)
                break;
            ans.push_back(i.second);
            --k;
        }
        
        return ans;
    }
};