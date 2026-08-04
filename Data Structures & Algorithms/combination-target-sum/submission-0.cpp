class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    void backtrack(vector<int>& nums, int start, int target) {
        if (target == 0) { //found a valid combo
            res.push_back(current);
            return;
        }
        if (target < 0) { // exceeded the target
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]); //choose it
            backtrack(nums, i, target - nums[i]); // stay at same no cause we can reuse it
            current.pop_back(); //undo our choice
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        current.clear();
        backtrack(nums, 0, target);
        return res;
    }
};
