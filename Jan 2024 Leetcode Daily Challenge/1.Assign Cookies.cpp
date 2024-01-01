// 455. Assign Cookies

/*


Intuition
To maximize the number of content children, we should try to assign cookies starting from the child with the highest greed factor. Sorting both the greed factors and cookie sizes in allows us to efficiently match larger cookies with children having higher greed factors.

Approach
Sort the arrays g (greed factors) and s (cookie sizes).
Initialize variables maxNum, cookieIndex, and childIndex to keep track of the count of content children, the current cookie index, and the current child index, respectively.
Iterate through the arrays, comparing the size of the current cookie (s[cookieIndex]) with the greed factor of the current child (g[childIndex]).
If the current cookie is large enough, increment maxNum, and move to the next smaller cookie and smaller child.
If the current cookie is not large enough, move to the next smaller child.
Continue this process until either the cookies or the children are exhausted.
Return the final count of content children (maxNum).

Complexity
Time complexity: The time complexity is O(n log n), where n is the length of the larger array between g and s, due to the sorting step.
Space complexity: The space complexity is O(1).

*/

#include <bits/stdc++.h>

class Solution
{
public:
	int findContentChildren(vector<int> &g, vector<int> &s)
	{
		int cookiesNums = s.size();
		if (cookiesNums == 0)
			return 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int maxNum = 0;
		int cookieIndex = cookiesNums - 1;
		int childIndex = g.size() - 1;
		while (cookieIndex >= 0 && childIndex >= 0)
		{
			if (s[cookieIndex] >= g[childIndex])
			{
				maxNum++;
				cookieIndex--;
				childIndex--;
			}
			else
			{
				childIndex--;
			}
		}
		return maxNum;
	}
};