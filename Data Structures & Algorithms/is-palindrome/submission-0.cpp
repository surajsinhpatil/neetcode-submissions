class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        for(char it : s){
            if(isalnum(it)){ //checks whether the char is alphanumeric; it returns false for spaces & symbols eg ?
                check += tolower(it); //converts uppercase to lower case & adds to check
            }
        }

        int p = 0;
        int q = check.size() - 1;
        while(p < q) {
            if(check[p] != check[q]) return false;
            p++;
            q--;
        }
        return true;
    }
};
