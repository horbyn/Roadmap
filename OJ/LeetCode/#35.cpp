/*
 * 1、遍历数组
 * 2、判断 target 存在是通过相等作条件的；判断不存在是通过 target < nums[] 作条件的
 * 3、特殊情况是[1, 3, 5, 6]判断7；[1, 3]判断2，这两种情况退出循环是 i 都是最后一个，
 *      但是一个是插入下一个位置一个插入当前位置，所以引入标记 fless 来区分
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int numsSize = nums.size();
        int i = 0;
        int fless = 0;

        for(; i < numsSize; i++){
            if(target >= nums[i]){
                if(target == nums[i])    return i;
            }else{
                // 一遇到比 target 大的元素就退出循环
                if(i == numsSize - 1)    fless = 1;
                break;
            }
        }

        if(i == numsSize - 1){
            // 当下标都是数组最后一个时需要区分 target 位置
            if(fless)    return numsSize - 1;
            return numsSize;
        }else    return i;
    }
};