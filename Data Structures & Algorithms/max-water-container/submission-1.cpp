class Solution {
public:
    int maxArea(vector<int>& heights) {
        //Optimal SOl
        int maxarea = 0;
        int p = 0;
        int q = heights.size() - 1;

        while(p < q){
            int currentarea = (q - p) * min(heights[p], heights[q]);
            maxarea = max(currentarea, maxarea);
            if(heights[p] < heights[q]) p++;
            else q--;
        }
        return maxarea;
    }
};
