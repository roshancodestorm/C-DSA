
class Solution {
public:
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else {
            for (string p : parents[word]) {
                dfs(p, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        parents.clear();
        ans.clear();
        path.clear();

        unordered_set<string> dict(
            wordList.begin(), wordList.end()
        );

        if (!dict.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> visited;

            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();

                for (int j = 0; j < curr.size(); j++) {
                    string next = curr;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == curr[j]) continue;

                        next[j] = ch;

                        if (dict.count(next)) {

                            parents[next].push_back(curr);

                            // Push each word only once per level
                            if (!visited.count(next)) {
                                visited.insert(next);

                                if (next == endWord) {
                                    found = true;
                                }
                                else {
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
            }

            for (string w : visited) {
                dict.erase(w);
            }
        }

        if (!found) return {};

        dfs(endWord, beginWord);

        return ans;
    }
};
;
