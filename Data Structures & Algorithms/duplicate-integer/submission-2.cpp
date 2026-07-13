class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //solution 1- Optimal
        unordered_set<int> st;
        for(int num : nums){
            if(st.count(num)) return true;
            st.insert(num);
        }
        return false;

        //solution 2 - Not Optimal-
        // map<int , int> mpp;
        
        // for(int i = 0; i< nums.size(); i++){
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]>1) return true;
        // }
        // return false;

        

        //solution 3 -- Optimal
        // unordered_map<int, int> mp;

        // for(int i = 0; i < (int)nums.size(); i++){
        //     if(mp.count(nums[i])) return true;
        //     mp[nums[i]] = 1;
        // }
        // return false;
    }
};