/*
 * 1、比较f(i - 1) + nums[i]和nums[i]，数值更大的保存为f(i)
 * 2、从f(i)中选出值最大的
 */

/* EXAMPLE:
 * -2,    1,    -3,    4,    -1,    2,    1,    -5,    4
 * f=-2 >考虑-2+1和-1谁大
 *        f=-1 >考虑-1-3和-3谁大
 *              f=-3 >考虑-3+4和4谁大
 *                     f=4 >... ...
 */

int maxSubArray(int* nums, int numsSize){
    int i;
    int func = nums[0], max = func;

    if(numsSize == 1)    return max;

    for(i = 1; i < numsSize; i++){
        // 考虑f(i - 1) + nums[i]和nums[i]谁更大
        if(func + nums[i] > nums[i])    func = func + nums[i];
        else    func = nums[i];

        // 从f(i)中选出最大值
        if(max < func)    max = func;
    }

    return max;
}