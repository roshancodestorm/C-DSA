class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int target, int start, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;

            temp.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return ans;
    }
};