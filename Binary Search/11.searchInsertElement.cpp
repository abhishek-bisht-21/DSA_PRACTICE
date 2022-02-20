// 35. Search Insert Position

class Solution
{
public:
	int searchInsert(vector<int> &arr, int data)
	{
		int n = arr.size(), si = 0, ei = n - 1;
		while (si <= ei)
		{
			int mid = si + (ei - si) / 2;
			if (arr[mid] <= data)
				si = mid + 1;
			else
				ei = mid - 1;
		}

		return (si - 1 >= 0 && arr[si - 1] == data) ? si - 1 : si;
	}
};
