#include<iostream>
#include<vector>
using namespace std;

// the interval from [s to m] and [m+1 to e] in v are sorted
// the function will merge both of these intervals
// such the interval from [s to e] in v becomes sorted
void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int main() {

	int n;
	vector<int> v;

	cout << "Enter Size of Vector : ";
	cin >> n;
	v = vector<int>(n);
	cout << "Enter Elements of Vector : ";
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	MergeSort(v, 0, n - 1);

	cout << "\nVector Obtained After Sorting: ";
	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}

}


// _______________________________________ LEETCODE SOLUTION_________________________________________________________

class Solution {
public:
    
    vector<int> merge(vector<int> &arr1, vector<int> &arr2){
        
        if (arr1.size() == 0 || arr2.size() == 0)
            return arr1.size() == 0 ? arr2 : arr1;
        
        int n = arr1.size() + arr2.size();
        vector<int> ans(n,0);
        int i=0;
        int j=0;
        int k=0;
        
        while(i < arr1.size() && j < arr2.size()){
            
            if(arr1[i] <= arr2[j]){
                ans[k++] = arr1[i++];
                
            }else{
                ans[k++] = arr2[j++];
               
            }
        }
        
        while(i < arr1.size()){
            ans[k++] = arr1[i++];
            
        }
        
        while(j < arr2.size()){
            ans[k++] = arr2[j++]; 
        }
        
        return ans;
        
    }
    
    vector<int> mergeSort(vector<int> &nums, int si, int ei){
        
        if(si == ei){
            vector<int> base;
            base.push_back(nums[si]);
            return base;
        }
        int mid = (si+ei)/2;
        vector<int> fsh = mergeSort(nums,si,mid);
        vector<int> ssh = mergeSort(nums,mid+1,ei);
        return merge(fsh,ssh);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};