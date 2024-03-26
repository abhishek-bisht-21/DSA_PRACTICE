int consecutiveOnes(vector<int>& arr){
    //Write your code here.

    int maxAns = 0;
    int count1 = 0;

    for(int ele: arr){
        if(ele == 1){
            count1++;
            maxAns = max(maxAns, count1);
        }else{
	// If we found a 0, reset the consecutive one count to 0
            count1 = 0;
        }
    }

    return maxAns;
}


/**
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    Where N is the length of the array.
**/