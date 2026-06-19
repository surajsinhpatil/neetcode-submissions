class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int top = 0;
        int bottom = m - 1;
        while (top <= bottom) 
        {
            int middle = top + ((bottom - top) / 2);
            if (matrix[middle][0] > target)
            {
                //bs code here
                int low = 0;
                int high = matrix[0].size() - 1;
                while (low <= high)
                {
                    int mid = low + ((high - low) / 2);
                    if (matrix[middle][mid] == target) return true;
                    else if (matrix[middle][mid] < target) low = mid + 1;
                    else high = mid - 1;
                    
                }
                bottom = middle - 1;
            }
            else if (matrix[middle][0] < target)
            {
                //bs code here
                int low = 0;
                int high = matrix[0].size() - 1;
                while (low <= high)
                {
                    int mid = low + ((high - low) / 2);
                    if (matrix[middle][mid] == target) return true;
                    else if (matrix[middle][mid] < target) low = mid + 1;
                    else high = mid - 1;
                    
                }
                top = middle + 1;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
};
