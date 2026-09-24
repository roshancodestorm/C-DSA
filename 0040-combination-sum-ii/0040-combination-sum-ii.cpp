class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& a, int target, int start, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < a.size(); i++) {
            if (i > start && a[i] == a[i - 1])
                continue;

            if (a[i] > target)
                break;

            temp.push_back(a[i]);
            solve(a, target - a[i], i + 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(candidates, target, 0, temp);

        return ans;
    }
};