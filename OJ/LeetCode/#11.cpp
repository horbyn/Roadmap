class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0;

        while (i != j) {
            int tmp = min(height[i], height[j]) * (j - i);
            if (area < tmp)    area = tmp;

            if (height[i] <= height[j])    i++;
            else    j--;
        }

        return area;
    }
};
