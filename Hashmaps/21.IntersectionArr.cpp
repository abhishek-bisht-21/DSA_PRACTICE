// Intersection of two arrays 

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_set<int> uset;
        
        for(int i=0;i<n;i++){
            uset.insert(a[i]);
        }
        
        int count = 0;
        
        for(int i=0;i<m;i++){
            int key = b[i];
            if(uset.find(key) != uset.end()){
                count++;
                uset.erase(key);
            }
        }
        
        return count;
    }
};