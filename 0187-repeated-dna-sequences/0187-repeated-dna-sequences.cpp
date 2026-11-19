
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<string> seen;
        unordered_set<string> repeated;

        vector<string> ans;

        for (int i = 0; i + 10 <= s.size(); i++) {

            string sub = s.substr(i, 10);

            if (seen.count(sub)) {
                repeated.insert(sub);
            }
            else {
                seen.insert(sub);
            }
        }

        for (string str : repeated) {
            ans.push_back(str);
        }

        return ans;
    }
};
