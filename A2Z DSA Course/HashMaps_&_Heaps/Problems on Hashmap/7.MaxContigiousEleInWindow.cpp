
// When (Max-Min) == (ith Index - jth Index)

int solution(){

	int ans=0;

	for(int i=0;i<n-1;i++){
		int maxi = arr[i];
		int mini = arr[i];
		unordered_set<int> checkDuplicates;
		checkDuplicates(arr[i]);
		for(int j=i+1;j<n;i++){
			if(checkDuplicates.find(arr[i]) != checkDuplicates.end()){
				break;
			}

			checkDuplicates.insert(arr[i]);
			mini = min(mini,arr[i]);
			maxi = max(maxi,arr[i]);

			
			if(j-i == max-min){
				int len = j-i+1;
				ans = max(ans,len);
			}
		}
	}

	return ans;
}