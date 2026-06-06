class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BRUTE FORCE
        int n = s.length();
        int l = 0;
        int maxlength = 0;
        if (n == 0) return 0;
        for (int r = 0; r < n; r++){
            for (int i = l; i < r; i++){
                if (s[i] == s[r]){
                    l = i + 1;
                    break;
                }
            }
            maxlength = max(maxlength, r - l + 1);
        }
        return maxlength;
    }
};
