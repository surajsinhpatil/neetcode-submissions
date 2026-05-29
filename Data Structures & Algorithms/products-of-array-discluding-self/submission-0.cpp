class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //OPTIMAL SOL
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        vector<int>ans(n);

        //build prefix array
        prefix[0] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        //build suffix array
        suffix[n-1] = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        //building answer
        for(int i = 0; i < n; i++){
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
