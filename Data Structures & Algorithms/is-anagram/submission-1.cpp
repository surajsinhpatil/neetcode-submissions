class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;

        for(char it : s){
            mp[it]++;
        }
        for(char it : t){
            mp[it]--;
        }
        for(const auto& it : mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
