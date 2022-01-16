class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())    return false;

        // =============== 思想：判右上角 ================
        int col = matrix[0].size(), row = matrix.size();
        int i = 0, j = col - 1;//i 指示当前行, j 指示当前列

        while (j >= 0 && i <= row - 1) {
            if (matrix[i][j] == target)    return true;
            else if (matrix[i][j] > target)    j--;
            else    i++;
        }

        return false;
    }
};
