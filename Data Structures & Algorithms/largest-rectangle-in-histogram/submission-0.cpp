class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); //sentinel
        int n = heights.size();
        int maxarea = 0;
        stack<int> st; // store indices
        
        for (int i = 0; i < n; i++){
            while (!st.empty() && heights[i] < heights[st.top()]){
            int j = st.top(); st.pop();
            int left = st.empty() ? 0 : st.top() + 1;
            int width = i - left;
            maxarea = max(maxarea, heights[j] * width);
            }
            st.push(i);
        }
        return maxarea;
    }
};
