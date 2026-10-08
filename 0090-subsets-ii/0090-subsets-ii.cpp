class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int start, vector<int>& temp) {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            backtrack(nums, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        backtrack(nums, 0, temp);

        return ans;
    }
};