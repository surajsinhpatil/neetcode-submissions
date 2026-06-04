class Solution {
public:
    bool isValid(string s) {
        //OPTIMAL SOL
        stack<char> st;
        unordered_map<char, char> closetoopen = {{')', '('}, {']', '['}, {'}', '{'}};

        for(char c : s){
            if (closetoopen.count(c)){
                if (!st.empty() && st.top() == closetoopen[c]){//stack not empty and top element should be opening bracket of the incoming clode bracket
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else st.push(c);
        }
        return st.empty();
    }
};
