/*
 * NOTE:
 *      我用暴力解超时[捂脸]，参考下面链接的思路重写才通过
 *      https://leetcode-cn.com/problems/majority-element/solution/chao-jian-ji-suan-fa-onshi-jian-fu-za-du-o1kong-ji/
 * 
 * 0、需要注意的是，题目说了给定数组“必定”存在多数元素，因此只要满足“大于n/2”就必定是当前元素
 * 1、先假定第一个元素为多数元素，每遍历一个元素就记录该元素出现次数
 * 2、只有在遇到不同元素的情况下才减少次数
 * 3、判断：如果次数已经减少至0，即说明之前检查的元素恰好是一半，此时重新假定多数元素；如果遍历完数组出现次数非零，那么当前元素即多数元素
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, nr = 1, max = nums[0];
        int numsSize = nums.size();

        for(i = 1; i < numsSize; i++){
            if(!nr){
                max = nums[i];
                nr++;
            }else{
                if(nums[i] == max){
                    nr++;
                }else{
                    nr--;
                }
            }
        }

        return max;
    }
};