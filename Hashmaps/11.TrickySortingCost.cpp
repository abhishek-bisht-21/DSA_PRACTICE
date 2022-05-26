// Tricky Sorting Cost 

class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        
        map<int,int> mp;
        int mx =0;
        for(int i=0;i<N;i++)
        {
           if(mp.find(arr[i]-1)!=mp.end())
           mp[arr[i]] = mp[arr[i]-1];
          
          mp[arr[i]]++;
           mx = max(mx ,mp[arr[i]]);
        }
        
	// mx-> max contigious subseq
        return N-mx;
    }
};