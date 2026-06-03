class Solution {
public:
    int maxArea(vector<int>& heights) {
        //BRUTE FORCE
        int maxarea = 0;
        for(int i = 0; i < heights.size(); i++){
            for(int j = i + 1; j < heights.size(); j++){
                int currentarea = (j - i) * min(heights[i], heights[j]);
                maxarea = max(currentarea, maxarea);
            }
        }
        return maxarea;
    }
};
