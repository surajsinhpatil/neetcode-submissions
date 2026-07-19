class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for (int digit : digits) {
            num = num * 10 + digit;
        }
        num++;
        vector<int> res;
        if (num == 0) res.push_back(0);
        while (num > 0) {
            res.push_back(num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
