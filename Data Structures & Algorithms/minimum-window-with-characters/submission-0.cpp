class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window; //created hashmaps
        for (char c : t) {
            countT[c]++;  //filled hashmap of t
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1}; //for ans
        int resLen = INT_MAX;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r]; //took the element in c
            window[c]++; //filled the string s hashmap

            if (countT.count(c) && window[c] == countT[c]) {
                have++; //check the single elemnt and increase have if value is same
            }

            while (have == need) { //update the result now
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--; //keep shrinking from left but check for valuable element
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
