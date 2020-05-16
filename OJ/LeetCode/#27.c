/*
 * 双指针：
 * 1、慢指针指示修改后的数组
 * 2、快指针找与val不相等的元素，再赋值到慢指针指向的元素
 * 3、快慢指针后移
 */

int removeElement(int* nums, int numsSize, int val){
    int i = 0, j = 0;

    for(j = 0; j < numsSize; j++){
        if(nums[j] != val){
            // 与val不相等，快指针指向元素复制到慢指针指向元素
            nums[i++] = nums[j];
        }
        else{
            // 与val相等即该元素要被删去，将慢指针指向元素修改为0
            nums[i] = 0;
        }
    }

    return i;
}