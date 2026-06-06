class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int result = 0;
        int l = 0;
        int maxfreq = 0;//most freq count in current window

        for(int r = 0; r < s.size(); r++){
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);

            int windowsize = r - l + 1;

            if(windowsize - maxfreq > k){
                mp[s[l]]--; //remove leftmost character
                l++; //shrink from left
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
