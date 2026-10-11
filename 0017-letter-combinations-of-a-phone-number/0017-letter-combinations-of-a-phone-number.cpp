class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr;

        function<void(int)> backtrack = [&](int i) {
            if (i == digits.size()) {
                ans.push_back(curr);
                return;
            }

            for (char c : mp[digits[i] - '0']) {
                curr.push_back(c);
                backtrack(i + 1);
                curr.pop_back();
            }
        };

        backtrack(0);
        return ans;
    }
};