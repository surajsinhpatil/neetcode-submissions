class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> freq;
        vector<int> ans;

        for(int it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            freq.push_back({it.second, it.first});
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        for(int i = 0; i < k; i++){
            ans.push_back(freq[i].second);
        }
        
        return ans;
    }
};
