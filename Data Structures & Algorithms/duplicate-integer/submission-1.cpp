class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums){
            if(st.count(num)) return true;
            st.insert(num);
        }
        return false;
        // map<int , int> mpp;
        
        // for(int i = 0; i< nums.size(); i++){
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]>1) return true;
        // }
        // return false;
    }
};