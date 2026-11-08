
class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(string &s, int start) {
        if (start == s.size()) {
            return {""};
        }

        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> ans;

        string word = "";

        for (int i = start; i < s.size(); i++) {
            word += s[i];

            if (dict.count(word)) {
                vector<string> remaining = solve(s, i + 1);

                for (string sentence : remaining) {
                    if (sentence.empty()) {
                        ans.push_back(word);
                    } else {
                        ans.push_back(word + " " + sentence);
                    }
                }
            }
        }

        return memo[start] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            dict.insert(word);
        }

        return solve(s, 0);
    }
};
