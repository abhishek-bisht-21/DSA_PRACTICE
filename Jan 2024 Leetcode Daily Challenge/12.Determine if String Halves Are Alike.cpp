
// 1704. Determine if String Halves Are Alike

#include <bits/stdc++.h>
class Solution {
public:
    bool halvesAreAlike(std::string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowelsCount = 0;
        int midIndex = s.length() / 2;

        for (int i = 0; i < midIndex; i++) {
            char charA = s[i];
            char charB = s[midIndex + i];
            if (vowels.count(charA)) vowelsCount++;
            if (vowels.count(charB)) vowelsCount--;
        }

        return vowelsCount == 0;
    }
};

