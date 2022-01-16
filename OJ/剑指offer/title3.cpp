class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int > st;

       for (int i = 0; i < nums.size(); ++i) {
           if (st.find(nums[i]) == st.end())    st.insert(nums[i]);
           else    return nums[i];
       }

        return -1;
    }
};
