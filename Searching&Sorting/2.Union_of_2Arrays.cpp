// Approach 1 Using Hashset

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        set<int> unique;
        
        for(int i=0;i<n;i++){
            unique.insert(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            unique.insert(arr2[i]);
        }
        
        vector<int> ans;
        for(auto ele:unique){
            ans.push_back(ele);
        }
        
        return ans;
    }
};


// Appraoch 2

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        
        int i=0;
        int j=0;
        
        while(i < n and j < m){
            if(arr1[i] == arr2[j]){
                
                if(ans.size() > 0){
                    
                    int last_ele = ans.back();
                    if(last_ele != arr1[i]){
                        ans.push_back(arr1[i]);
                    }
                }else{
                    ans.push_back(arr1[i]);
                }
                
                i++;
                j++;
            }else if(arr1[i] < arr2[j]){
                
                if(ans.size() > 0){
                    
                    int last_ele = ans.back();
                    if(last_ele != arr1[i]){
                        ans.push_back(arr1[i]);
                    }
                }else{
                    ans.push_back(arr1[i]);
                }
                
                i++;
            }else{
                
                
                if(ans.size() > 0){
                    
                    int last_ele = ans.back();
                    if(last_ele != arr2[j]){
                        ans.push_back(arr2[j]);
                    }
                }else{
                    ans.push_back(arr2[j]);
                }
                
                j++;
            }
        }
        
        while(j < m){
             int last_ele = ans.back();
                if(last_ele != arr2[j]){
                    ans.push_back(arr2[j]);
                }
                
                j++;
        }
        
          while(i < n){
             int last_ele = ans.back();
                if(last_ele != arr1[i]){
                    ans.push_back(arr1[i]);
                }
                
                i++;
        }
        
        return ans;
    }
};



