

void sortK(vector<int> &arr, int n, int k){

	// Insert first k+1 element in the min Heap
	priority_queue<int,vector<int>, greater<int>> pq(arr,arr+k+1);

	
	int index = 0;
	for(int i=k+1;i<n;i++){
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while(pq.empty() == false){
		arr[index++] = pq.top();
		pq.pop();
	}
}