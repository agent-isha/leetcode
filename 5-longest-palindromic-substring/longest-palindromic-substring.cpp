class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int len = 1;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            //odd length performance

            
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > len) {
                    len = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            //even length palindrome
            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > len) {
                    len = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, len);
    }
};