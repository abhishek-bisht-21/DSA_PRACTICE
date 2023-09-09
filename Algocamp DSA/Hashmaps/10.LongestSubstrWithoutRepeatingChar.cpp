
// Longest Substring without Repeating Characters
class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
	}
};


/*

Approach 2
We improve upon the first solution by using an unordered map (charMap) instead of a set.

The map stores characters as keys and their indices as values.

We still maintain the left and right pointers and the maxLength variable.
We iterate through the string using the right pointer.

If the current character is not in the map or its index is less than left, it means it is a new unique character.

We update the charMap with the character's index and update the maxLength if necessary.

If the character is repeating within the current substring, we move the left pointer to the next position after the last occurrence of the character.
We update the index of the current character in the charMap and continue the iteration.

At the end, we return the maxLength as the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        
        return maxLength;
    }
};