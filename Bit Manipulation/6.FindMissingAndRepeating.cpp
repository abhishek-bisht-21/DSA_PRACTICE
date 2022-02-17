class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
int *ans=new int[2];
       unordered_map<int,int>m;
       for(int i=1;i<=n;i++){
           m[i]=0;
       }
       for(int i=0;i<n;i++){
           m[arr[i]]++;
       }
       for(int i=1;i<=n;i++){
           if(m[i]>1) ans[0]=i;
           if(m[i]==0) ans[1]=i;
       }
       return ans;
    }
};
