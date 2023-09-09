// Longest K unique characters substring

class Solution{
    public:
            int longestKSubstr(string s, int k)
	{
		// your code here
		unordered_map<char, int> mp;
		for (auto it : s)
			mp[it]++;
		if (mp.size() < k)
			return -1;

		mp.clear();
		int j = 0, i = 0, maxlen = 0;

		while (j < s.size())
		{
			mp[s[j]]++;

			if (mp.size() == k)
			{
				maxlen = max(maxlen, j - i + 1);
			}
			while (mp.size() > k)
			{
				mp[s[i]]--;
				if (mp[s[i]] == 0)
					mp.erase(s[i]);
				i++;
			}
			j++;
		}
		return maxlen;
	}
};