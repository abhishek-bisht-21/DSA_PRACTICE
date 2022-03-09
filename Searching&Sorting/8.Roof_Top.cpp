// Approach 1
class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       //Your code here
       int cnt = 0;
       int maxi = INT_MIN;
     
       
       for(int i=1;i<N;i++){
           if(A[i-1] < A[i]){
               cnt++;
           }else{
               maxi = max(cnt,maxi);
               cnt = 0;
              
           }
       }
       
       return max(maxi,cnt);
    }
};


