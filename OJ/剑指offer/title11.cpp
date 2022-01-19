class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size = numbers.size();
        int pivot = numbers[0];

        for (int i = 0; i < size; ++i) {
            if (numbers[i] < pivot)    return numbers[i];
        }

        return pivot;
    }
};
