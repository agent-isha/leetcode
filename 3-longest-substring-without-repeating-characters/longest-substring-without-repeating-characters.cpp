class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxi = 0;
        unordered_map<char, int> isha;

        while (j < s.size()) {
            isha[s[j]]++;

            
            while (isha[s[j]] > 1) {
                isha[s[i]]--;
                i++;
            }

            
            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};