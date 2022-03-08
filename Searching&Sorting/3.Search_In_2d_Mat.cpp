/*

	1) To find the Potential Row in a sorted 2d Matrix.
	2) To find target in this potential row.

*/

// Approach 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int pr = findPotentialRow(matrix,target); //log n
        
        if(pr == -1) {
            return false;
        }
        
        return binarySearch(matrix,pr,target); //log m
    }
    
    int findPotentialRow(vector<vector<int>>matrix,int target) {
        int lo = 0;
        int hi = matrix.size()-1;
        int lc = matrix[0].size()-1;
        
        while(lo <= hi) {
            
            int m = (lo + hi)/2;
            
            if(matrix[m][0] <= target && matrix[m][lc] >= target) {
                return m;
            }
            else if(matrix[m][0] > target) {
                hi = m-1;
            }
            else {
                lo = m+1;
            }
        }
        
        return -1;
    }
    
    bool binarySearch(vector<vector<int>>matrix,int r,int target) {
        int lo = 0;
        int hi = matrix[0].size()-1;
        
        while(lo <= hi) {
            
            int m = (lo + hi)/2;
            
            if(matrix[r][m] == target) {
                return true;
            }
            else if(matrix[r][m] < target) {
                lo = m+1;
            }
            else {
                hi = m-1;
            }
        }
        
        return false;
    }
};

// Approach 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
	int m = matrix[0].size();
	int si = 0;
	int ei = n * m - 1;

	while (si <= ei)
	{
		int mid = (si + ei) / 2;
		int r = mid / m;
		int c = mid % m;

		if (matrix[r][c] == target)
			return true;

		else if (matrix[r][c] < target)
			si = mid + 1;

		else
			ei = mid - 1;
	}

	return false;
    }
};