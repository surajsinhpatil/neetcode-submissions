class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //BRUTE FORCE
        for(int p = 0; p < numbers.size(); p++){
            for(int q = p + 1; q < numbers.size(); q++){
                if(numbers[p] + numbers[q] == target) return {p + 1, q + 1};
                
            }
        }
        return {};
    }
};
