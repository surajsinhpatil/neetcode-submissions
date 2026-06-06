class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //OPTIMAL SOL
        unordered_map<char, int> mp;//to store last index of each character
        int l = 0;
        int maxlength = 0;

        for( int r = 0; r < s.size(); r++){
            if (mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            maxlength = max(maxlength, r - l + 1);
        }
        return maxlength;
    }
};
