class Solution {
public:
    vector<bool> used;
    vector<int> current;
    vector<vector<int>> res;

    void backtrack(vector<int>& nums) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            current.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        backtrack(nums);
        return res;
    }
};
