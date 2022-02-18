// TC -> O(No. of Bits)
int countBits(int n){

	int count = 0;
	while(n){
		count += (n&1);
		n = n>>1;
	}

	return count;
}


// TC -> O(No. of Set Bits)
int countBits(int n){

	int count = 0;
	while(n){
		count++;
		n = (n & (n-1)); // Remove the Last Set Bit
		
	}

	return count;
}