class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> freq;

        for (string& word : words)
            freq[word]++;

        int n = s.size();
        int len = words[0].size();
        int total = words.size() * len;

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > freq[word]) {
                        string first = s.substr(left, len);
                        seen[first]--;
                        left += len;
                        count--;
                    }

                    if (count == (int)words.size()) {
                        ans.push_back(left);

                        string first = s.substr(left, len);
                        seen[first]--;
                        left += len;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};