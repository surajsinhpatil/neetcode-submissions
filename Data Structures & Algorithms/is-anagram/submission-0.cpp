class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        // multiset<char> sms;
        // multiset<char> tms;
        // for(auto it : s){
        //     sms.insert(it);
        // }
        // for(auto it : t){
        //     tms.insert(it);
        // }
        // return sms == tms;

        unordered_map<char, int> mp;

        for(char it : s){
            mp[it]++;
        }
        for(char it : t){
            mp[it]--;
        }
        for(auto it : mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
