class Solution {
    public:
   int numIdenticalPairs(vector<int>& nums) {
     // Your code goes here
     unordered_map<int,int> umap; // ele, freq
      int goodPair = 0;

      for(int ele: nums){
          if(umap.find(ele) != umap.end()){
              goodPair += umap[ele];
          }
          umap[ele]++;
      }  

      return goodPair;

   }
};