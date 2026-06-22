class TimeMap { //BRUTE FORCE Solution
public:
    unordered_map<string, vector<pair<string,int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        string ans = "";

        for (auto &p : mp[key])
        {
            if (p.second <= timestamp) ans = p.first;
            else break;
        }
        return ans;
    }
};
