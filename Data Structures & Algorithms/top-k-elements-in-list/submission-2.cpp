class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int it : nums){
            mp[it]++;
        }
        vector<vector<int>> freq(nums.size()+1); //bcoz each freq can correspond to multiple numbers
        for(auto it : mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = nums.size(); i >= 1; i--){
            for(int num : freq[i]){ //accessing the sub vector of freq[i]
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
            
        }
        return ans;
    }
};
