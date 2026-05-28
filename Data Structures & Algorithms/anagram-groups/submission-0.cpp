class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            string cp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(cp); //since cp is string and not vector<string> which is our value of unordered map
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
