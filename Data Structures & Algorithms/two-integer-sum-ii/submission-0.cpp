class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int p = 0;
        int q = numbers.size() - 1;

        while(p < q){

            if(numbers[p] + numbers[q] > target) q--;
            if(numbers[p] + numbers[q] < target) p++;
            if(numbers[p] + numbers[q] == target) {
                ans.push_back(p + 1);
                ans.push_back(q + 1);
                return ans;
            }
        }
        return {};
    }
};
