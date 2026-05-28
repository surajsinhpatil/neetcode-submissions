class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for( int i=0; i< nums.size(); i++){
        //     int toget = target - nums[i];
        //     auto it= find(nums.begin()+i+1, nums.end(), toget);
        //     if( it != nums.end()){
        //         int secondindex = it - nums.begin();
        //         return {i, secondindex};
        //     } 
        // }
        // return {};

        unordered_map<int, int> mp;
        for( int i = 0; i < (int)nums.size(); i++){
            int need = target - nums[i];

            if(mp.find(need) != mp.end()){
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
