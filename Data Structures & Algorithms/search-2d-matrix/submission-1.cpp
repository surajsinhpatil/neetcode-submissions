class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        while (top <= bottom)
        {
            int middle = top + ((bottom - top) / 2);

            if (matrix[middle][0] > target) bottom = middle - 1;
            else if (matrix[middle].back() < target) top = middle + 1;
            else 
            {
                int low = 0;
                int high = matrix[0].size() - 1;

                while (low <= high)
                {
                    int mid = low + ((high - low) / 2);

                    if (matrix[middle][mid] == target) return true;
                    else if (matrix[middle][mid] > target) high = mid - 1;
                    else low = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};
