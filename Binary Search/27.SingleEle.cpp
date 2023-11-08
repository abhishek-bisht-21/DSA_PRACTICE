 /*
Index   0 1 2 3 4 5 6 7 8 9 10
 arr = [1 1 2 2 3 3 4 5 5 6 6]
 
  
  When both 'odd' and 'even' index have same element.
 (even, odd) -> Single Element is on the right side (Eliminate Left Half). 
 (odd, even) -> Single Element is on the left side (Eliminate right Half).
 
 How to know we are at single element -> (arr[mid-1] != arr[mid] and arr[mid] != arr[mid+1])

 We are checking for left and right to figure out single element. Therefore we have to take care of 
 a lot of corner cases. What if we are at the 1st index or last. Therefore we will try to eliminate
 these conditional cases. We will trim down our search space. This is not neccessary we our doing it
 to improve our code readibility.
 

 540. Single Element in a Sorted Array
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    // even, odd -> Eliminate Left
	// odd even  -> Eliminate Right
	int n = arr.size();
	if(n == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];

	int low = 1;
	int high = n-2;

	while(low <= high){
		int mid = (low+high)/2;
		
		if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
			return arr[mid];
		}

		// We are on left half
		if((mid % 2 == 1 && arr[mid-1] == arr[mid]) ||( mid % 2 == 0 && arr[mid] == arr[mid+1])){
			low = mid+1;
		}else{
			// We are on right half
			high = mid-1;
		}
	}

	return -1;
    }
};