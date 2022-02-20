
class Solution{
    public:
int findClosest(int arr[], int n, int target) 
   { 
       // Complete the function
      int l=0;
      int h=n-1;
      while(l<=h){
          int mid=l+(h-l)/2;
          if(arr[mid]==target){
              return target;
          }
          else if(arr[mid]<target){
              l=mid+1;
              if(l>n-1){
                  return arr[n-1];
              }
          }
          else{
              h=mid-1;
              if(h<0){
                  return arr[0];
              }
          }
      }
     int res1=abs(arr[l]-target);
     int res2=abs(arr[h]-target);
     if(res1==res2){
         return max(arr[l],arr[h]);
     }
     else if(res1<res2){
         return arr[l];
     }
     else{
         return arr[h];
     }
   } 
};