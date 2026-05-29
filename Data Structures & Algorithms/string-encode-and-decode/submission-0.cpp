class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string st : strs){
            int n = st.length();
            s = s + to_string(n) + "#" + st;
        }
        return s;
    }

    vector<string> decode(string s) {
            vector <string> result;
            //5#hello2#hi
            int i = 0;
            while( i < s.length()){
            int j = i;
            while(s[j] != '#') j++; //j now points #
            int len = stoi(s.substr(i, j-i));//extracted length from i to just before #
            string word = s.substr(j+1, len);
            result.push_back(word);
            i = j + 1 + len;
            }
            return result;
    }
};
