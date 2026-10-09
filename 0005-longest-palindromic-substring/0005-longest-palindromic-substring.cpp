class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 2; j++) {
                int left = i, right = i + j;

                while (left >= 0 && right < s.size() &&
                       s[left] == s[right]) {
                    if (right - left + 1 > maxLen) {
                        start = left;
                        maxLen = right - left + 1;
                    }
                    left--;
                    right++;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};