class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t)
            freq[c]++;

        int left = 0, start = 0, minLen = INT_MAX;
        int required = t.size();

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                required--;

            freq[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};