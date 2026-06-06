class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BETTER SOL
        unordered_set<int> st;
        int l = 0;
        int maxlength = 0;

        for(int r = 0; r < s.size(); r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxlength = max(maxlength, r - l + 1);
        }
        return maxlength;
    }
};
